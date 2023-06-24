#include "Window.h"
#include "WindowHandle.h"
#include "Display.h"

namespace Pazu
{
	Display::Display()
			: m_displayModes(SDL_GetNumVideoDisplays())
	{
		for (std::size_t x = 0; x < m_displayModes.size(); ++x)
		{
			m_displayModes[x].index = x;
			m_displayModes[x].name = SDL_GetDisplayName(x);
			m_displayModes[x].videoModes = FindVideoModes(x);
		}
	}

	Display &Display::Get()
	{
		static Display display;
		return display;
	}

	const std::vector<DisplayMode> &Display::GetModes() const
	{
		return m_displayModes;
	}

	const DisplayMode &Display::GetWindowMode(const Window &window) const
	{
		return m_displayModes[SDL_GetWindowDisplayIndex(window.GetHandle()->Get().get())];
	}

	std::vector<VideoMode> Display::FindVideoModes(const unsigned int index) const
	{
		const auto count = SDL_GetNumDisplayModes(index);
		std::vector<VideoMode> videoModes;
		SDL_DisplayMode displayMode;
		for (int x = 0; x < count; ++x)
		{
			SDL_GetDisplayMode(index, x, &displayMode);
			const Size size = {static_cast<unsigned int>(displayMode.w), static_cast<unsigned int>(displayMode.h)};
			const auto refreshRate = static_cast<unsigned int>(displayMode.refresh_rate);
			if (const auto pos = std::find_if(videoModes.begin(), videoModes.end(), [&size](const VideoMode &vm)
																				{ return vm.size == size; });
					pos == videoModes.cend())
				videoModes.emplace_back(VideoMode(size, {refreshRate}));
			else
				pos->refreshRates.emplace_back(refreshRate);
		}
		return videoModes;
	}
}

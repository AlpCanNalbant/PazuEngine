#pragma once

namespace Pazu
{
	enum class WindowFlag : unsigned int
	{
		Shown = SDL_WINDOW_SHOWN,
		Hidden = SDL_WINDOW_HIDDEN,
		Borderless = SDL_WINDOW_BORDERLESS,
		Resizable = SDL_WINDOW_RESIZABLE,
		Minimized = SDL_WINDOW_MINIMIZED,
		Maximized = SDL_WINDOW_MAXIMIZED,
		Fullscreen = SDL_WINDOW_FULLSCREEN,
		FullscreenBorderless = SDL_WINDOW_FULLSCREEN_DESKTOP
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::WindowFlag>
	{
		static constexpr int min{static_cast<int>(Pazu::WindowFlag::Shown)};								//Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::WindowFlag::FullscreenBorderless)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

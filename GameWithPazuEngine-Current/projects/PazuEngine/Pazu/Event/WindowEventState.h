#pragma once

namespace Pazu
{
	enum class WindowEventState : unsigned int
	{
		None = SDL_WINDOWEVENT_NONE,
		Shown = SDL_WINDOWEVENT_SHOWN,
		Hidden = SDL_WINDOWEVENT_HIDDEN,
		Moved = SDL_WINDOWEVENT_MOVED,
		Resized = SDL_WINDOWEVENT_SIZE_CHANGED,
		Minimized = SDL_WINDOWEVENT_MINIMIZED,
		Maximized = SDL_WINDOWEVENT_MAXIMIZED,
		Restored = SDL_WINDOWEVENT_RESTORED,
		MouseEntered = SDL_WINDOWEVENT_ENTER,
		MouseLeft = SDL_WINDOWEVENT_LEAVE,
		FocusGained = SDL_WINDOWEVENT_FOCUS_GAINED,
		FocusLost = SDL_WINDOWEVENT_FOCUS_LOST,
		Closed = SDL_WINDOWEVENT_CLOSE
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::WindowEventState>
	{
		static constexpr int min{static_cast<int>(Pazu::WindowEventState::None)};		//Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::WindowEventState::Closed)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

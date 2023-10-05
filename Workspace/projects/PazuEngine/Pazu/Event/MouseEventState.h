// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	enum class MouseEventState : unsigned int
	{
		None = 0,
		Moved = SDL_MOUSEMOTION,
		ButtonPressed = SDL_MOUSEBUTTONDOWN,
		ButtonReleased = SDL_MOUSEBUTTONUP,
		WheelScrolled = SDL_MOUSEWHEEL
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::MouseEventState>
	{
		static constexpr int min{static_cast<int>(Pazu::MouseEventState::None)};		  // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::MouseEventState::WheelScrolled)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

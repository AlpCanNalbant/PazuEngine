#pragma once

namespace Pazu
{
	enum class KeyboardEventState : unsigned int
	{
		None,
		KeyPressed = SDL_KEYDOWN,
		KeyReleased = SDL_KEYUP,
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::KeyboardEventState>
	{
		static constexpr int min{static_cast<int>(Pazu::KeyboardEventState::None)};				 //Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::KeyboardEventState::KeyReleased)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

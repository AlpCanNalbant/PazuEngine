#pragma once

namespace Pazu::Sdl
{
	enum class InitFlag : unsigned int
	{
		Timer = SDL_INIT_TIMER,
		Audio = SDL_INIT_AUDIO,
		Video = SDL_INIT_VIDEO,
		Joystick = SDL_INIT_JOYSTICK,
		Haptic = SDL_INIT_HAPTIC,
		GameController = SDL_INIT_GAMECONTROLLER,
		Events = SDL_INIT_EVENTS,
		Sensor = SDL_INIT_SENSOR,
		NoParachute = SDL_INIT_NOPARACHUTE,
		Everything = SDL_INIT_EVERYTHING
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Sdl::InitFlag>
	{
		static constexpr int min{static_cast<int>(Pazu::Sdl::InitFlag::Timer)};				//Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Sdl::InitFlag::NoParachute)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

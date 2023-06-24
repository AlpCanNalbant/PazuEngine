#pragma once

namespace Pazu
{
	enum class EventType
	{
		Mouse,
		Keyboard,
		Window,
		System,
		None
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::EventType>
	{
		static constexpr int min{static_cast<int>(Pazu::EventType::Mouse)}; //Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::EventType::None)};	//Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

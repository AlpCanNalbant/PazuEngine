#pragma once

namespace Pazu
{
	enum class Button : std::size_t
	{
		None,
		Left,
		Middle,
		Right
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Button>
	{
		static constexpr int min{static_cast<int>(Pazu::Button::None)};	 //Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Button::Right)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

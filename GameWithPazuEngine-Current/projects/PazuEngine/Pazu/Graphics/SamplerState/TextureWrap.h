#pragma once

namespace Pazu::Graphics
{
	enum class TextureWrap
	{
		Repeat,
		Mirror,
		Clamp
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::TextureWrap>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::TextureWrap::Repeat)};	 //Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::TextureWrap::Clamp)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

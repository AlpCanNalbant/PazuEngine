#pragma once

namespace Pazu::Graphics
{
	enum class TextureFilter
	{
		Nearest,
		Linear,
		Anisotropic
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::TextureFilter>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::TextureFilter::Nearest)};			//Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::TextureFilter::Anisotropic)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

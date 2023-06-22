#pragma once

namespace Pazu::Graphics
{
	enum class ShaderFlag
	{
		None = 0,
		Vertex = 1 << 0,
		Pixel = 1 << 1
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::ShaderFlag>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::ShaderFlag::None)};	 //Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::ShaderFlag::Pixel)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

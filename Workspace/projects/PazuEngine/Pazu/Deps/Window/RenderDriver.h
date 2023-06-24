#pragma once

namespace Pazu::Sdl
{
	enum class RenderDriver
	{
		None,
		Direct3D11,
		Direct3D,
		OpenGL,
		OpenGLES,
		OpenGLES2,
		Metal,
		Software
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Sdl::RenderDriver>
	{
		static constexpr int min{static_cast<int>(Pazu::Sdl::RenderDriver::None)};		 //Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Sdl::RenderDriver::Software)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

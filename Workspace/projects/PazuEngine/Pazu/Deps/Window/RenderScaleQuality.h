// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Sdl
{
	enum class RenderScaleQuality
	{
		None = -1,
		Nearest,
		Linear,
		Anisotropic
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Sdl::RenderScaleQuality>
	{
		static constexpr int min{static_cast<int>(Pazu::Sdl::RenderScaleQuality::None)};		// Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Sdl::RenderScaleQuality::Anisotropic)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

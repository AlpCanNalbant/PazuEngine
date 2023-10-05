// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	enum class Api
	{
		Direct3D11,
		OpenGL
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::Api>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::Api::Direct3D11)}; // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::Api::OpenGL)};	 // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

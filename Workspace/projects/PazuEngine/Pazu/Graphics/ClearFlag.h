// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	enum class ClearFlag : unsigned int
	{
		Color = 1 << 0,
		Depth = 1 << 1,
		Stencil = 1 << 2
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::ClearFlag>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::ClearFlag::Color)};	// Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::ClearFlag::Stencil)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	enum class VertexFlag
	{
		Position = 1 << 0,
		Normal = 1 << 1,
		Color = 1 << 2,
		Texture = 1 << 3
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::VertexFlag>
	{
		static constexpr int min{static_cast<int>(Pazu::VertexFlag::Position)}; // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::VertexFlag::Texture)};	// Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

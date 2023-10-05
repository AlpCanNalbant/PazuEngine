// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	enum class VertexInput
	{
		Position = 1 << 0,
		Normal = 1 << 1,
		Color = 1 << 2,
		Texture = 1 << 3,
		BlendIndices = 1 << 4,
		BlendWeights = 1 << 5
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::VertexInput>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::VertexInput::Position)};	   // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::VertexInput::BlendWeights)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

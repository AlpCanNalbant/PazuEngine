// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
// #include <array>
#include "Vertex.h"

namespace Pazu
{
	template <typename T = float>
	struct VertexBlendWeights : public Vertex<T, 4>
	{
		VertexBlendWeights() noexcept = default;
		VertexBlendWeights(const std::array<T, 4> &weights) noexcept;

		// std::array<T, 4> m_weights;
	};
}
#include "VertexBlendWeights.inl"

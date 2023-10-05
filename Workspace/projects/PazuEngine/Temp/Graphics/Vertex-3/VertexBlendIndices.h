// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
// #include <array>
#include "Vertex.h"

namespace Pazu
{
	template <typename T = unsigned int>
	struct VertexBlendIndices : public Vertex<T, 4>
	{
		VertexBlendIndices() noexcept = default;
		VertexBlendIndices(const std::array<T, 4> &indices) noexcept;

		// std::array<T, 4> m_indices;
	};
}
#include "VertexBlendIndices.inl"

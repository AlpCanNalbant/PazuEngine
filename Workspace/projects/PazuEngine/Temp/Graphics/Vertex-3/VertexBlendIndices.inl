// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexBlendIndices<T>::VertexBlendIndices(const std::array<T, 4> &indices) noexcept
		: Vertex<T, 4>(indices) {}
	// : m_indices(indices) {}
} // namespace Pazu

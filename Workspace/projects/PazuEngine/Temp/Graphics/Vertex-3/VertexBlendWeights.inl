// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexBlendWeights<T>::VertexBlendWeights(const std::array<T, 4> &weights) noexcept
		: Vertex<T, 4>(weights) {}
	// : m_weights(weights) {}
} // namespace Pazu

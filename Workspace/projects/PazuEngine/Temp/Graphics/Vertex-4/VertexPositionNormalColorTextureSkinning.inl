// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	VertexPositionNormalColorTextureSkinning<T1, T2, T3, T4, T5, T6>::VertexPositionNormalColorTextureSkinning(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 4> &color, const std::array<T4, 2> &texture, const std::array<T5, 2> &indices, const std::array<T6, 2> &weights) noexcept
		: m_position(position), m_normal(normal), m_color(color), m_texture(texture), m_indices(indices), m_weights(weights) {}
}

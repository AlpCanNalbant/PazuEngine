// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T1, typename T2, typename T3, typename T4>
	VertexPositionNormalColorTexture<T1, T2, T3, T4>::VertexPositionNormalColorTexture(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 4> &color, const std::array<T4, 2> &texture) noexcept
		: m_position(position), m_normal(normal), m_color(color), m_texture(texture) {}
}

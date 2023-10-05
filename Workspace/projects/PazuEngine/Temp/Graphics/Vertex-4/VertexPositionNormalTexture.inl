// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T1, typename T2, typename T3>
	VertexPositionNormalTexture<T1, T2, T3>::VertexPositionNormalTexture(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 2> &texture) noexcept
		: m_position(position), m_normal(normal), m_texture(texture) {}
}

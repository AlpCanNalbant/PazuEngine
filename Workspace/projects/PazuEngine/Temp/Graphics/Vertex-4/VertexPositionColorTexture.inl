// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T1, typename T2, typename T3>
	VertexPositionColorTexture<T1, T2, T3>::VertexPositionColorTexture(const std::array<T1, 3> &position, const std::array<T2, 4> &color, const std::array<T3, 2> &texture) noexcept
		: m_position(position), m_color(color), m_texture(texture) {}
}

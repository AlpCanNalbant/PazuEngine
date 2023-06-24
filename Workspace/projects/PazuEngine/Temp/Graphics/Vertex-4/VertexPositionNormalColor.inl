namespace Pazu
{
	template <typename T1, typename T2, typename T3>
	VertexPositionNormalColor<T1, T2, T3>::VertexPositionNormalColor(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 4> &color) noexcept
			: m_position(position), m_normal(normal), m_color(color) {}
}

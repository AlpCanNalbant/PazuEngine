namespace Pazu
{
	template <typename T1, typename T2>
	VertexPositionColor<T1, T2>::VertexPositionColor(const std::array<T1, 3> &position, const std::array<T2, 4> &color) noexcept
			: m_position(position), m_color(color) {}
}

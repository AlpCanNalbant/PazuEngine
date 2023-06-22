namespace Pazu
{
	template <typename T1, typename T2>
	VertexPositionNormal<T1, T2>::VertexPositionNormal(const std::array<T1, 3> &position, const std::array<T2, 3> &normal) noexcept
			: m_position(position), m_normal(normal) {}
}

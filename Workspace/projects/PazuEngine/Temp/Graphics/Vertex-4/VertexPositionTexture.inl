namespace Pazu
{
	template <typename T1, typename T2>
	VertexPositionTexture<T1, T2>::VertexPositionTexture(const std::array<T1, 3> &position, const std::array<T2, 2> &texture) noexcept
			: m_position(position), m_texture(texture) {}
}

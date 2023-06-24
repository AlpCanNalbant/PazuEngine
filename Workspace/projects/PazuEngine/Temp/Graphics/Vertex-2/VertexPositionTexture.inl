namespace Pazu
{
	template <typename T>
	VertexPositionTexture<T>::VertexPositionTexture(const std::array<T, 3> &position, const std::array<T, 2> &texture) noexcept
			: VertexPosition<T>(position), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_position.cbegin(), this->m_position.cend());
		data.insert(data.cend(), this->m_texture.cbegin(), this->m_texture.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Texture;
	}
} // namespace Pazu

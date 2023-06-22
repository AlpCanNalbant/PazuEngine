namespace Pazu
{
	template <typename T>
	VertexPositionNormalTexture<T>::VertexPositionNormalTexture(const std::array<T, 3> &position, const std::array<T, 3> &normal, const std::array<T, 2> &texture) noexcept
			: VertexPosition<T>(position), VertexNormal<T>(normal), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionNormalTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_position.cbegin(), this->m_position.cend());
		data.insert(data.cend(), this->m_normal.cbegin(), this->m_normal.cend());
		data.insert(data.cend(), this->m_texture.cbegin(), this->m_texture.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormalTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal | VertexFlag::Texture;
	}
} // namespace Pazu

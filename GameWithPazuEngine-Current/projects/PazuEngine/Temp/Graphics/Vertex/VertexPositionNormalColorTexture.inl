namespace Pazu
{
	template <typename T>
	VertexPositionNormalColorTexture<T>::VertexPositionNormalColorTexture(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData, const std::array<T, 4> &colorData, const std::array<T, 2> &textureData) noexcept
			: VertexPosition<T>(positionData), VertexNormal<T>(normalData), VertexColor<T>(colorData), VertexTexture<T>(textureData) {}

	template <typename T>
	VertexPositionNormalColorTexture<T>::VertexPositionNormalColorTexture(const Vector3 &position, const Vector3 &normal, const Color &color, const Vector2 &texture) noexcept
			: VertexPosition<T>(position), VertexNormal<T>(normal), VertexColor<T>(color), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionNormalColorTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_normalData.cbegin(), this->m_normalData.cend());
		data.insert(data.cend(), this->m_colorData.cbegin(), this->m_colorData.cend());
		data.insert(data.cend(), this->m_textureData.cbegin(), this->m_textureData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormalColorTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal | VertexFlag::Color | VertexFlag::Texture;
	}
} // namespace Pazu

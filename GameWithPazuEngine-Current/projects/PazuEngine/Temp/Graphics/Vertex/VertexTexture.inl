namespace Pazu
{
	template <typename T>
	VertexTexture<T>::VertexTexture(const std::array<T, 2> &textureData) noexcept
			: m_textureData(textureData) {}

	template <typename T>
	VertexTexture<T>::VertexTexture(const Vector2 &texture) noexcept
	{
		SetTexture(texture);
	}

	template <typename T>
	VertexTexture<T>::~VertexTexture() noexcept = default;

	template <typename T>
	Vector2 VertexTexture<T>::GetTexture() const noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			return {m_textureData[0], m_textureData[1]};
		else
			return {static_cast<float>(m_textureData[0]), static_cast<float>(m_textureData[1])};
	}

	template <typename T>
	void VertexTexture<T>::SetTexture(const Vector2 &texture) noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			m_textureData = {texture.x, texture.y};
		else
			m_textureData = {static_cast<T>(texture.x), static_cast<T>(texture.y)};
	}
} // namespace Pazu

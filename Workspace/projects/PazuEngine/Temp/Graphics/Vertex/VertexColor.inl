namespace Pazu
{
	template <typename T>
	VertexColor<T>::VertexColor(const std::array<T, 4> &colorData) noexcept
			: m_colorData(colorData) {}

	template <typename T>
	VertexColor<T>::VertexColor(const Color &color) noexcept
	{
		SetColor(color);
	}

	template <typename T>
	VertexColor<T>::~VertexColor() noexcept = default;

	template <typename T>
	Color VertexColor<T>::GetColor() const noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			return {m_colorData[0], m_colorData[1], m_colorData[2], m_colorData[3]};
		else
			return {static_cast<float>(m_colorData[0]), static_cast<float>(m_colorData[1]), static_cast<float>(m_colorData[2]), static_cast<float>(m_colorData[3])};
	}

	template <typename T>
	void VertexColor<T>::SetColor(const Color &color) noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			m_colorData = {color.x, color.y, color.z, color.w};
		else
			m_colorData = {static_cast<T>(color.x), static_cast<T>(color.y), static_cast<T>(color.z), static_cast<T>(color.w)};
	}
} // namespace Pazu

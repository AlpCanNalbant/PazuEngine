namespace Pazu
{
	template <typename T>
	VertexPositionNormalColor<T>::VertexPositionNormalColor(const std::array<T, 3> &position, const std::array<T, 3> &normal, const std::array<T, 4> &color) noexcept
			: VertexPosition<T>(position), VertexNormal<T>(normal), VertexColor<T>(color) {}

	template <typename T>
	std::vector<T> VertexPositionNormalColor<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_position.cbegin(), this->m_position.cend());
		data.insert(data.cend(), this->m_normal.cbegin(), this->m_normal.cend());
		data.insert(data.cend(), this->m_color.cbegin(), this->m_color.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormalColor<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal | VertexFlag::Color;
	}
} // namespace Pazu

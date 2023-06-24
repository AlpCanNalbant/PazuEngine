namespace Pazu
{
	template <typename T>
	VertexPositionColor<T>::VertexPositionColor(const std::array<T, 3> &position, const std::array<T, 4> &color) noexcept
			: VertexPosition<T>(position), VertexColor<T>(color) {}

	template <typename T>
	std::vector<T> VertexPositionColor<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_position.cbegin(), this->m_position.cend());
		data.insert(data.cend(), this->m_color.cbegin(), this->m_color.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionColor<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Color;
	}
} // namespace Pazu

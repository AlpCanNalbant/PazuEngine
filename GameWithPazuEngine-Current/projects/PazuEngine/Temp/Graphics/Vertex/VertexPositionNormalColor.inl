namespace Pazu
{
	template <typename T>
	VertexPositionNormalColor<T>::VertexPositionNormalColor(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData, const std::array<T, 4> &colorData) noexcept
			: VertexPosition<T>(positionData), VertexNormal<T>(normalData), VertexColor<T>(colorData) {}

	template <typename T>
	VertexPositionNormalColor<T>::VertexPositionNormalColor(const Vector3 &position, const Vector3 &normal, const Color &color) noexcept
			: VertexPosition<T>(position), VertexNormal<T>(normal), VertexColor<T>(color) {}

	template <typename T>
	std::vector<T> VertexPositionNormalColor<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_normalData.cbegin(), this->m_normalData.cend());
		data.insert(data.cend(), this->m_colorData.cbegin(), this->m_colorData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormalColor<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal | VertexFlag::Color;
	}
} // namespace Pazu

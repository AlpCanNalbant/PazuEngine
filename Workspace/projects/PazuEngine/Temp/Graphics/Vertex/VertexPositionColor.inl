// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionColor<T>::VertexPositionColor(const std::array<T, 3> &positionData, const std::array<T, 4> &colorData) noexcept
		: VertexPosition<T>(positionData), VertexColor<T>(colorData) {}

	template <typename T>
	VertexPositionColor<T>::VertexPositionColor(const Vector3 &position, const Color &color) noexcept
		: VertexPosition<T>(position), VertexColor<T>(color) {}

	template <typename T>
	std::vector<T> VertexPositionColor<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_colorData.cbegin(), this->m_colorData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionColor<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Color;
	}
} // namespace Pazu

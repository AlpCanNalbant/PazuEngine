// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionNormal<T>::VertexPositionNormal(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData) noexcept
		: VertexPosition<T>(positionData), VertexNormal<T>(normalData) {}

	template <typename T>
	VertexPositionNormal<T>::VertexPositionNormal(const Vector3 &position, const Vector3 &normal) noexcept
		: VertexPosition<T>(position), VertexNormal<T>(normal) {}

	template <typename T>
	std::vector<T> VertexPositionNormal<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_normalData.cbegin(), this->m_normalData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormal<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal;
	}
} // namespace Pazu

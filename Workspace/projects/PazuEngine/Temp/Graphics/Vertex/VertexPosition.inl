// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPosition<T>::VertexPosition(const std::array<T, 3> &positionData) noexcept
		: m_positionData(positionData) {}

	template <typename T>
	VertexPosition<T>::VertexPosition(const Vector3 &position) noexcept
	{
		SetPosition(position);
	}

	template <typename T>
	Vector3 VertexPosition<T>::GetPosition() const noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			return {m_positionData[0], m_positionData[1], m_positionData[2]};
		else
			return {static_cast<float>(m_positionData[0]), static_cast<float>(m_positionData[1]), static_cast<float>(m_positionData[2])};
	}

	template <typename T>
	void VertexPosition<T>::SetPosition(const Vector3 &position) noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			m_positionData = {position.x, position.y, position.z};
		else
			m_positionData = {static_cast<T>(position.x), static_cast<T>(position.y), static_cast<T>(position.z)};
	}

	template <typename T>
	std::vector<T> VertexPosition<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.begin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPosition<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position;
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionNormal<T>::VertexPositionNormal(const std::array<T, 3> &position, const std::array<T, 3> &normal) noexcept
		: VertexPosition<T>(position), VertexNormal<T>(normal) {}

	template <typename T>
	std::vector<T> VertexPositionNormal<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_position.cbegin(), this->m_position.cend());
		data.insert(data.cend(), this->m_normal.cbegin(), this->m_normal.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormal<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal;
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexNormal<T>::VertexNormal(const std::array<T, 3> &normalData) noexcept
		: m_normalData(normalData) {}

	template <typename T>
	VertexNormal<T>::VertexNormal(const Vector3 &normal) noexcept
	{
		SetNormal(normal);
	}

	template <typename T>
	VertexNormal<T>::~VertexNormal() noexcept = default;

	template <typename T>
	Vector3 VertexNormal<T>::GetNormal() const noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			return {m_normalData[0], m_normalData[1], m_normalData[2]};
		else
			return {static_cast<float>(m_normalData[0]), static_cast<float>(m_normalData[1]), static_cast<float>(m_normalData[2])};
	}

	template <typename T>
	void VertexNormal<T>::SetNormal(const Vector3 &normal) noexcept
	{
		if constexpr (std::is_same_v<T, float>)
			m_normalData = {normal.x, normal.y, normal.z};
		else
			m_normalData = {static_cast<T>(normal.x), static_cast<T>(normal.y), static_cast<T>(normal.z)};
	}
} // namespace Pazu

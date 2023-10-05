// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionNormalTexture<T>::VertexPositionNormalTexture(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData, const std::array<T, 2> &textureData) noexcept
		: VertexPosition<T>(positionData), VertexNormal<T>(normalData), VertexTexture<T>(textureData) {}

	template <typename T>
	VertexPositionNormalTexture<T>::VertexPositionNormalTexture(const Vector3 &position, const Vector3 &normal, const Vector2 &texture) noexcept
		: VertexPosition<T>(position), VertexNormal<T>(normal), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionNormalTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_normalData.cbegin(), this->m_normalData.cend());
		data.insert(data.cend(), this->m_textureData.cbegin(), this->m_textureData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionNormalTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Normal | VertexFlag::Texture;
	}
} // namespace Pazu

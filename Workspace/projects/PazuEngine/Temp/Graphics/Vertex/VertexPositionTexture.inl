// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionTexture<T>::VertexPositionTexture(const std::array<T, 3> &positionData, const std::array<T, 2> &textureData) noexcept
		: VertexPosition<T>(positionData), VertexTexture<T>(textureData) {}

	template <typename T>
	VertexPositionTexture<T>::VertexPositionTexture(const Vector3 &position, const Vector2 &texture) noexcept
		: VertexPosition<T>(position), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_textureData.cbegin(), this->m_textureData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Texture;
	}
} // namespace Pazu

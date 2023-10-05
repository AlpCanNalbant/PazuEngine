// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionColorTexture<T>::VertexPositionColorTexture(const std::array<T, 3> &positionData, const std::array<T, 4> &colorData, const std::array<T, 2> &textureData) noexcept
		: VertexPosition<T>(positionData), VertexColor<T>(colorData), VertexTexture<T>(textureData) {}

	template <typename T>
	VertexPositionColorTexture<T>::VertexPositionColorTexture(const Vector3 &position, const Color &color, const Vector2 &texture) noexcept
		: VertexPosition<T>(position), VertexColor<T>(color), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionColorTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_positionData.cbegin(), this->m_positionData.cend());
		data.insert(data.cend(), this->m_colorData.cbegin(), this->m_colorData.cend());
		data.insert(data.cend(), this->m_textureData.cbegin(), this->m_textureData.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionColorTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Color | VertexFlag::Texture;
	}
} // namespace Pazu

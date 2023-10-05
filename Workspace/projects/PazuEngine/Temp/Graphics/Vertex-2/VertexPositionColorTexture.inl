// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPositionColorTexture<T>::VertexPositionColorTexture(const std::array<T, 3> &position, const std::array<T, 4> &color, const std::array<T, 2> &texture) noexcept
		: VertexPosition<T>(position), VertexColor<T>(color), VertexTexture<T>(texture) {}

	template <typename T>
	std::vector<T> VertexPositionColorTexture<T>::ToData() const noexcept
	{
		std::vector<T> data;
		data.insert(data.cbegin(), this->m_position.cbegin(), this->m_position.cend());
		data.insert(data.cend(), this->m_color.cbegin(), this->m_color.cend());
		data.insert(data.cend(), this->m_texture.cbegin(), this->m_texture.cend());
		return data;
	}

	template <typename T>
	VertexFlag VertexPositionColorTexture<T>::GetFlags() const noexcept
	{
		return VertexFlag::Position | VertexFlag::Color | VertexFlag::Texture;
	}
} // namespace Pazu

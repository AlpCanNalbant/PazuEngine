#pragma once
#include "../../Math/Vector2.h"

namespace Pazu
{
	template <typename T>
	class VertexTexture
	{
	public:
		VertexTexture() noexcept = default;
		VertexTexture(const std::array<T, 2> &textureData) noexcept;
		VertexTexture(const Vector2 &texture) noexcept;
		VertexTexture(const VertexTexture &other) noexcept = default;
		VertexTexture(VertexTexture &&temp) noexcept = default;
		virtual ~VertexTexture() noexcept = 0;
		VertexTexture &operator=(const VertexTexture &other) noexcept = default;
		VertexTexture &operator=(VertexTexture &&temp) noexcept = default;
		Vector2 GetTexture() const noexcept;
		void SetTexture(const Vector2 &texture) noexcept;

	protected:
		std::array<T, 2> m_textureData;
	};
} // namespace Pazu
#include "VertexTexture.inl"

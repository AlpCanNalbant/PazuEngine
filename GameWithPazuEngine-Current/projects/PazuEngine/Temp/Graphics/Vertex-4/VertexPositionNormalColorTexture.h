#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float, typename T3 = float, typename T4 = float>
	struct VertexPositionNormalColorTexture
	{
		VertexPositionNormalColorTexture() noexcept = default;
		VertexPositionNormalColorTexture(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 4> &color, const std::array<T4, 2> &texture) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 3> m_normal;
		std::array<T3, 4> m_color;
		std::array<T4, 2> m_texture;
	};
} // namespace Pazu
#include "VertexPositionNormalColorTexture.inl"

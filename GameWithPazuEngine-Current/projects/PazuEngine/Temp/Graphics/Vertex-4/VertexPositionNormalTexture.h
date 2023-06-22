#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float, typename T3 = float>
	struct VertexPositionNormalTexture
	{
		VertexPositionNormalTexture() noexcept = default;
		VertexPositionNormalTexture(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 2> &texture) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 3> m_normal;
		std::array<T3, 2> m_texture;
	};
} // namespace Pazu
#include "VertexPositionNormalTexture.inl"

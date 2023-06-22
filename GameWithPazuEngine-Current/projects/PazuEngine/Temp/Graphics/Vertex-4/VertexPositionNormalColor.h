#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float, typename T3 = float>
	struct VertexPositionNormalColor
	{
		VertexPositionNormalColor() noexcept = default;
		VertexPositionNormalColor(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 4> &color) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 3> m_normal;
		std::array<T3, 4> m_color;
	};
} // namespace Pazu
#include "VertexPositionNormalColor.inl"

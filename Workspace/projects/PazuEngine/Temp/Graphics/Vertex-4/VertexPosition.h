#pragma once
#include <array>

namespace Pazu
{
	template <typename T = float>
	struct VertexPosition
	{
		VertexPosition() noexcept = default;
		VertexPosition(const std::array<T, 3> &position) noexcept;

		std::array<T, 3> m_position;
	};
} // namespace Pazu
#include "VertexPosition.inl"

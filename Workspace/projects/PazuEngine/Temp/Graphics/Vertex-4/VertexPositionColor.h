// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float>
	struct VertexPositionColor
	{
		VertexPositionColor() noexcept = default;
		VertexPositionColor(const std::array<T1, 3> &position, const std::array<T2, 4> &color) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 4> m_color;
	};
} // namespace Pazu
#include "VertexPositionColor.inl"

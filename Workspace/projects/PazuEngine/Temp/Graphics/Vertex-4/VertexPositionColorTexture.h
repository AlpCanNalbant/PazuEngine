// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float, typename T3 = float>
	struct VertexPositionColorTexture
	{
		VertexPositionColorTexture() noexcept = default;
		VertexPositionColorTexture(const std::array<T1, 3> &position, const std::array<T2, 4> &color, const std::array<T3, 2> &texture) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 4> m_color;
		std::array<T3, 2> m_texture;
	};
} // namespace Pazu
#include "VertexPositionColorTexture.inl"

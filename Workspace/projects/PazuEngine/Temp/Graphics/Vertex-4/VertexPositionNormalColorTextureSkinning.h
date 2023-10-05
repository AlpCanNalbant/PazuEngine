// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float, typename T3 = float, typename T4 = float, typename T5 = unsigned int, typename T6 = float>
	struct VertexPositionNormalColorTextureSkinning
	{
		VertexPositionNormalColorTextureSkinning() noexcept = default;
		VertexPositionNormalColorTextureSkinning(const std::array<T1, 3> &position, const std::array<T2, 3> &normal, const std::array<T3, 4> &color, const std::array<T4, 2> &texture, const std::array<T5, 2> &indices, const std::array<T6, 2> &weights) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 3> m_normal;
		std::array<T3, 4> m_color;
		std::array<T4, 2> m_texture;
		std::array<T5, 4> m_indices;
		std::array<T6, 4> m_weights;
	};
} // namespace Pazu
#include "VertexPositionNormalColorTextureSkinning.inl"

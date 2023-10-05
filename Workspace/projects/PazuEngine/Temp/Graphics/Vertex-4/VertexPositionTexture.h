// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float>
	struct VertexPositionTexture : public VertexPosition<T1>, public VertexTexture<T2>
	{
		VertexPositionTexture() noexcept = default;
		VertexPositionTexture(const std::array<T1, 3> &position, const std::array<T2, 2> &texture) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 2> m_texture;
	};
} // namespace Pazu
#include "VertexPositionTexture.inl"

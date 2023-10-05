// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <array>

namespace Pazu
{
	template <typename T1 = float, typename T2 = float>
	struct VertexPositionNormal
	{
		VertexPositionNormal() noexcept = default;
		VertexPositionNormal(const std::array<T1, 3> &position, const std::array<T2, 3> &normal) noexcept;

		std::array<T1, 3> m_position;
		std::array<T2, 3> m_normal;
	};
} // namespace Pazu
#include "VertexPositionNormal.inl"

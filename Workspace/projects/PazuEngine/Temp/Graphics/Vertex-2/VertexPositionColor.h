// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "VertexPosition.h"
#include "VertexColor.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionColor : public VertexPosition<T>, public VertexColor<T>
	{
	public:
		VertexPositionColor() noexcept = default;
		VertexPositionColor(const std::array<T, 3> &position, const std::array<T, 4> &color) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionColor.inl"

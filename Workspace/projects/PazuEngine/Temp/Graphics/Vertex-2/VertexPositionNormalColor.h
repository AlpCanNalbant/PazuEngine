// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"
#include "VertexColor.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormalColor : public VertexPosition<T>, public VertexNormal<T>, public VertexColor<T>
	{
	public:
		VertexPositionNormalColor() noexcept = default;
		VertexPositionNormalColor(const std::array<T, 3> &position, const std::array<T, 3> &normal, const std::array<T, 4> &color) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormalColor.inl"

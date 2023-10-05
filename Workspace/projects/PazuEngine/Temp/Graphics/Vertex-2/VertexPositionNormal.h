// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormal : public VertexPosition<T>, public VertexNormal<T>
	{
	public:
		VertexPositionNormal() noexcept = default;
		VertexPositionNormal(const std::array<T, 3> &position, const std::array<T, 3> &normal) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormal.inl"

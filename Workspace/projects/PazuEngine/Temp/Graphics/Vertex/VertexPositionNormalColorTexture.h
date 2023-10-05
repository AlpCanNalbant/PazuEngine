// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"
#include "VertexColor.h"
#include "VertexTexture.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormalColorTexture : public VertexPosition<T>, public VertexNormal<T>, public VertexColor<T>, public VertexTexture<T>
	{
	public:
		VertexPositionNormalColorTexture() noexcept = default;
		VertexPositionNormalColorTexture(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData, const std::array<T, 4> &colorData, const std::array<T, 2> &textureData) noexcept;
		VertexPositionNormalColorTexture(const Vector3 &position, const Vector3 &normal, const Color &color, const Vector2 &texture) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormalColorTexture.inl"

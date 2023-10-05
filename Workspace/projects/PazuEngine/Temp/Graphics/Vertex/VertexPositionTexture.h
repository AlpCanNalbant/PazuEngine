// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "VertexPosition.h"
#include "VertexTexture.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionTexture : public VertexPosition<T>, public VertexTexture<T>
	{
	public:
		VertexPositionTexture() noexcept = default;
		VertexPositionTexture(const std::array<T, 3> &positionData, const std::array<T, 2> &textureData) noexcept;
		VertexPositionTexture(const Vector3 &position, const Vector2 &texture) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionTexture.inl"

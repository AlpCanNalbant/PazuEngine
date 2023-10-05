// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionNormalTexture
	{
		VertexPositionNormalTexture() = default;
		constexpr VertexPositionNormalTexture(const Vector3 &position, const Vector3 &normal, const Vector2 &texture);

		Vector3 position;
		Vector3 normal;
		Vector2 texture;
	};
} // namespace Pazu
#include "VertexPositionNormalTexture.inl"

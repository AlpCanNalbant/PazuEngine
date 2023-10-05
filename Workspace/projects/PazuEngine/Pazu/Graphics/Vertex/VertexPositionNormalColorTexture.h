// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Color.h"
#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionNormalColorTexture
	{
		VertexPositionNormalColorTexture() = default;
		constexpr VertexPositionNormalColorTexture(const Vector3 &position, const Vector3 &normal, const Color &color, const Vector2 &texture);

		Vector3 position;
		Vector3 normal;
		Color color;
		Vector2 texture;
	};
} // namespace Pazu
#include "VertexPositionNormalColorTexture.inl"

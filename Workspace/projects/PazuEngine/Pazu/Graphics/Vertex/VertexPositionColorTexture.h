// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Color.h"
#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionColorTexture
	{
		VertexPositionColorTexture() = default;
		constexpr VertexPositionColorTexture(const Vector3 &position, const Color &color, const Vector2 &texture);

		Vector3 position;
		Color color;
		Vector2 texture;
	};
} // namespace Pazu
#include "VertexPositionColorTexture.inl"

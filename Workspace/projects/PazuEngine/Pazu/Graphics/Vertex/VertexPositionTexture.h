// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionTexture
	{
		VertexPositionTexture() = default;
		constexpr VertexPositionTexture(const Vector3 &position, const Vector2 &texture);

		Vector3 position;
		Vector2 texture;
	};
} // namespace Pazu
#include "VertexPositionTexture.inl"

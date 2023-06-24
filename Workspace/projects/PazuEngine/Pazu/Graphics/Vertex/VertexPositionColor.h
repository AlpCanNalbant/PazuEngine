#pragma once
#include "../../Math/Color.h"
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionColor
	{
		VertexPositionColor() = default;
		constexpr VertexPositionColor(const Vector3 &position, const Color &color);

		Vector3 position;
		Color color;
	};
} // namespace Pazu
#include "VertexPositionColor.inl"

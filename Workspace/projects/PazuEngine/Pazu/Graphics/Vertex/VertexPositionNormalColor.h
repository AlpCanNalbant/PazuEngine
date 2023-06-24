#pragma once
#include "../../Math/Color.h"
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionNormalColor
	{
		VertexPositionNormalColor() = default;
		constexpr VertexPositionNormalColor(const Vector3 &position, const Vector3 &normal, const Color &color);

		Vector3 position;
		Vector3 normal;
		Color color;
	};
} // namespace Pazu
#include "VertexPositionNormalColor.inl"

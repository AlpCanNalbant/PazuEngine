#pragma once
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPositionNormal
	{
		VertexPositionNormal() = default;
		constexpr VertexPositionNormal(const Vector3 &position, const Vector3 &normal);

		Vector3 position;
		Vector3 normal;
	};
} // namespace Pazu
#include "VertexPositionNormal.inl"

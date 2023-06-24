#pragma once
#include "../../Math/Vector3.h"

namespace Pazu::Graphics
{
	struct VertexPosition
	{
		VertexPosition() = default;
		constexpr VertexPosition(const Vector3 &position);

		Vector3 position;
	};
} // namespace Pazu
#include "VertexPosition.inl"

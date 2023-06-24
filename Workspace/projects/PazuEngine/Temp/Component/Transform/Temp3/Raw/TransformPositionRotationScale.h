#pragma once
#include "TransformPositionRotation.h"
#include "TransformScale.h"

namespace Pazu
{
	class TransformPositionRotationScale : public TransformPositionRotation, public TransformScale
	{
	public:
		Matrix CreateWorld() noexcept;
	};
} // namespace Pazu

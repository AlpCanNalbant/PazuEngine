#pragma once
#include "TransformPositionRotationComponent.h"
#include "TransformScaleComponent.h"

namespace Pazu
{
	class TransformPositionRotationScaleComponent : public TransformPositionRotationComponent, public TransformScaleComponent
	{
	public:
		Matrix CreateWorld() noexcept;
	};
} // namespace Pazu

#pragma once
#include "TransformPositionRotationComponent.h"
#include "TransformScaleComponent.h"

namespace Pazu
{
	class TransformPositionRotationScaleComponent : public TransformPositionRotationComponent, public TransformScaleComponent
	{
	};
} // namespace Pazu

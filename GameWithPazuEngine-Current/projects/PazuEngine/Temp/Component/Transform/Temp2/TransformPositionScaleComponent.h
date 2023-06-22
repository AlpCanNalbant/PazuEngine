#pragma once
#include "TransformPositionComponent.h"
#include "TransformScaleComponent.h"

namespace Pazu
{
	class TransformPositionScaleComponent : public TransformPositionComponent, public TransformScaleComponent
	{
	};
} // namespace Pazu

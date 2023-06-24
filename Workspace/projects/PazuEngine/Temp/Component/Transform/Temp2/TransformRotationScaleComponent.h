#pragma once
#include "TransformRotationComponent.h"
#include "TransformScaleComponent.h"

namespace Pazu
{
	class TransformRotationScaleComponent : public TransformRotationComponent, public TransformScaleComponent
	{
	};
} // namespace Pazu

#pragma once
#include "TransformPositionComponent.h"
#include "TransformRotationComponent.h"

namespace Pazu
{
	class TransformPositionRotationComponent : public TransformPositionComponent, public TransformRotationComponent
	{
	};
} // namespace Pazu

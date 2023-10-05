// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TransformPositionRotationComponent.h"
#include "TransformScaleComponent.h"

namespace Pazu
{
	class TransformPositionRotationScaleComponent : public TransformPositionRotationComponent, public TransformScaleComponent
	{
	};
} // namespace Pazu

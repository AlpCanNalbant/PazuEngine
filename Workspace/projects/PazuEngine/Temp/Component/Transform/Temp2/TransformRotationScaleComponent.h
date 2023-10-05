// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TransformRotationComponent.h"
#include "TransformScaleComponent.h"

namespace Pazu
{
	class TransformRotationScaleComponent : public TransformRotationComponent, public TransformScaleComponent
	{
	};
} // namespace Pazu

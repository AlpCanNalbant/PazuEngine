// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TransformPositionComponent.h"
#include "TransformRotationComponent.h"

namespace Pazu
{
	class TransformPositionRotationComponent : public TransformPositionComponent, public TransformRotationComponent
	{
	};
} // namespace Pazu

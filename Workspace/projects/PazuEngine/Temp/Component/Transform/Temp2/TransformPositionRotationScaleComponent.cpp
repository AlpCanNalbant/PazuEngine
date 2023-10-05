// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TransformPositionRotationScaleComponent.h"

namespace Pazu
{
	Matrix TransformPositionRotationScaleComponent::CreateWorld() noexcept
	{
		return CreateScale() * CreateRotation() * CreateTranslation();
	}
}

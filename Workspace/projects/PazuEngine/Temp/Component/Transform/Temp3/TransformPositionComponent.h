// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../IComponent.h"
#include "Raw/TransformPosition.h"

namespace Pazu
{
	class TransformPositionComponent : public TransformPosition, public IComponent
	{
	};
} // namespace Pazu

#pragma once
#include "../IComponent.h"
#include "Raw/TransformPosition.h"

namespace Pazu
{
	class TransformPositionComponent : public TransformPosition, public IComponent
	{
	};
} // namespace Pazu

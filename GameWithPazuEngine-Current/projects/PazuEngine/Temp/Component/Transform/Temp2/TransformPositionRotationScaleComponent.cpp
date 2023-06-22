#include "TransformPositionRotationScaleComponent.h"

namespace Pazu
{
	Matrix TransformPositionRotationScaleComponent::CreateWorld() noexcept
	{
		return CreateScale() * CreateRotation() * CreateTranslation();
	}
}

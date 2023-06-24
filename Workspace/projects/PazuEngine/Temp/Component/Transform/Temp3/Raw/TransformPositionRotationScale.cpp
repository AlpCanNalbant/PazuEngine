#include "TransformPositionRotationScale.h"

namespace Pazu
{
	Matrix TransformPositionRotationScale::CreateWorld() noexcept
	{
		return CreateScale() * CreateRotation() * CreateTranslation();
	}
}

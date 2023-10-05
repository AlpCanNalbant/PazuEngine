// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TransformPositionRotationScale.h"

namespace Pazu
{
	Matrix TransformPositionRotationScale::CreateWorld() noexcept
	{
		return CreateScale() * CreateRotation() * CreateTranslation();
	}
}

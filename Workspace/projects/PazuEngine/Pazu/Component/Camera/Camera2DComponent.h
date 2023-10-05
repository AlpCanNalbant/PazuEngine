// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "CameraComponent.h"

namespace Pazu
{
	class Camera2DComponent : public CameraComponent
	{
	public:
		Camera2DComponent();
		void CalculateProjection() final;
	};
} // namespace Pazu

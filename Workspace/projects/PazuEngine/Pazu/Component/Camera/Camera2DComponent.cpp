// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Camera2DComponent.h"

namespace Pazu
{
	Camera2DComponent::Camera2DComponent()
	{
		m_far = 1.f;
	}

	void Camera2DComponent::CalculateProjection()
	{
		m_projection = Matrix::CreateOrthographicOffCenter(0.f, static_cast<float>(m_viewSize.x), static_cast<float>(m_viewSize.y), 0.f, m_near, m_far);
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Camera3DComponent.h"

namespace Pazu
{
	Camera3DComponent::Camera3DComponent()
	{
		m_far = 10000.f;
	}

	void Camera3DComponent::CalculateProjection()
	{
		m_projection = Matrix::CreatePerspectiveFieldOfView(Mathf::ToRadians(m_fov), static_cast<float>(m_viewSize.x) / static_cast<float>(m_viewSize.y), m_near, m_far);
	}

	float Camera3DComponent::GetFov() const
	{
		return m_fov;
	}

	void Camera3DComponent::SetFov(const float fov)
	{
		m_fov = fov;
		m_dirty = true;
	}
} // namespace Pazu

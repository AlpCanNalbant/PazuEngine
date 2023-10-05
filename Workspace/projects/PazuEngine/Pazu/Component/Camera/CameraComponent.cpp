// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "CameraComponent.h"

namespace Pazu
{
	const Matrix &CameraComponent::GetProjection() const
	{
		return m_projection;
	}

	bool CameraComponent::GetDirty() const
	{
		return m_dirty;
	}

	const Size &CameraComponent::GetViewSize() const
	{
		return m_viewSize;
	}

	float CameraComponent::GetNear() const
	{
		return m_near;
	}

	float CameraComponent::GetFar() const
	{
		return m_far;
	}

	void CameraComponent::SetProjection(const Matrix &projection)
	{
		m_projection = projection;
	}

	void CameraComponent::SetDirty(const bool dirty)
	{
		m_dirty = dirty;
	}

	void CameraComponent::SetViewSize(const Size &viewSize)
	{
		m_viewSize = viewSize;
		m_dirty = true;
	}

	void CameraComponent::SetNear(const float nearAmount)
	{
		m_near = nearAmount;
		m_dirty = true;
	}

	void CameraComponent::SetFar(const float farAmount)
	{
		m_far = farAmount;
		m_dirty = true;
	}
} // namespace Pazu

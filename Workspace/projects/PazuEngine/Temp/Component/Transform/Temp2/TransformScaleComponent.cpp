// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TransformScaleComponent.h"

namespace Pazu
{
	Matrix TransformScaleComponent::CreateScale() noexcept
	{
		return Matrix::CreateScale(m_scale);
	}

	void TransformScaleComponent::Scale(const Vector3 &scale) noexcept
	{
		m_scale += scale;
		m_dirty = true;
	}

	void TransformScaleComponent::Scale(const float width, const float height, const float depth) noexcept
	{
		Scale({width, height, depth});
	}

	void TransformScaleComponent::Scale(const float scale) noexcept
	{
		Scale({scale, scale, scale});
	}

	const Vector3 &TransformScaleComponent::GetScale() const noexcept
	{
		return m_scale;
	}

	float TransformScaleComponent::GetWidth() const noexcept
	{
		return m_scale.x;
	}

	float TransformScaleComponent::GetHeight() const noexcept
	{
		return m_scale.y;
	}

	float TransformScaleComponent::GetDepth() const noexcept
	{
		return m_scale.z;
	}

	void TransformScaleComponent::SetScale(const Vector3 &scale) noexcept
	{
		m_scale = scale;
		m_dirty = true;
	}

	void TransformScaleComponent::SetScale(const float width, const float height, const float depth) noexcept
	{
		SetScale({width, height, depth});
	}

	void TransformScaleComponent::SetScale(const float scale) noexcept
	{
		SetScale({scale, scale, scale});
	}

	void TransformScaleComponent::SetWidth(const float width) noexcept
	{
		m_scale.x = width;
		m_dirty = true;
	}

	void TransformScaleComponent::SetHeight(const float height) noexcept
	{
		m_scale.y = height;
		m_dirty = true;
	}

	void TransformScaleComponent::SetDepth(const float depth) noexcept
	{
		m_scale.z = depth;
		m_dirty = true;
	}
} // namespace Pazu

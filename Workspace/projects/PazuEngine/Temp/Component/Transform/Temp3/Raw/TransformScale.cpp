// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TransformScale.h"

namespace Pazu
{
	Matrix TransformScale::CreateScale() noexcept
	{
		return Matrix::CreateScale(m_scale);
	}

	void TransformScale::Scale(const Vector3 &scale) noexcept
	{
		m_scale += scale;
		m_dirty = true;
	}

	void TransformScale::Scale(const float width, const float height, const float depth) noexcept
	{
		Scale({width, height, depth});
	}

	void TransformScale::Scale(const float scale) noexcept
	{
		Scale({scale, scale, scale});
	}

	const Vector3 &TransformScale::GetScale() const noexcept
	{
		return m_scale;
	}

	float TransformScale::GetWidth() const noexcept
	{
		return m_scale.x;
	}

	float TransformScale::GetHeight() const noexcept
	{
		return m_scale.y;
	}

	float TransformScale::GetDepth() const noexcept
	{
		return m_scale.z;
	}

	void TransformScale::SetScale(const Vector3 &scale) noexcept
	{
		m_scale = scale;
		m_dirty = true;
	}

	void TransformScale::SetScale(const float width, const float height, const float depth) noexcept
	{
		SetScale({width, height, depth});
	}

	void TransformScale::SetScale(const float scale) noexcept
	{
		SetScale({scale, scale, scale});
	}

	void TransformScale::SetWidth(const float width) noexcept
	{
		m_scale.x = width;
		m_dirty = true;
	}

	void TransformScale::SetHeight(const float height) noexcept
	{
		m_scale.y = height;
		m_dirty = true;
	}

	void TransformScale::SetDepth(const float depth) noexcept
	{
		m_scale.z = depth;
		m_dirty = true;
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TransformScale.h"

namespace Pazu
{
	void TransformScale::CalculateScale()
	{
		m_matrix = Matrix::CreateScale(m_scale);
	}

	void TransformScale::Scale(const Vector3 &scale)
	{
		m_scale += scale;
		m_dirty = true;
	}

	void TransformScale::Scale(const float width, const float height, const float depth)
	{
		Scale({width, height, depth});
	}

	void TransformScale::Scale(const float scale)
	{
		Scale({scale, scale, scale});
	}

	const Vector3 &TransformScale::GetScale() const
	{
		return m_scale;
	}

	float TransformScale::GetWidth() const
	{
		return m_scale.x;
	}

	float TransformScale::GetHeight() const
	{
		return m_scale.y;
	}

	float TransformScale::GetDepth() const
	{
		return m_scale.z;
	}

	void TransformScale::SetScale(const Vector3 &scale)
	{
		m_scale = scale;
		m_dirty = true;
	}

	void TransformScale::SetScale(const float width, const float height, const float depth)
	{
		SetScale({width, height, depth});
	}

	void TransformScale::SetScale(const float scale)
	{
		SetScale({scale, scale, scale});
	}

	void TransformScale::SetWidth(const float width)
	{
		m_scale.x = width;
		m_dirty = true;
	}

	void TransformScale::SetHeight(const float height)
	{
		m_scale.y = height;
		m_dirty = true;
	}

	void TransformScale::SetDepth(const float depth)
	{
		m_scale.z = depth;
		m_dirty = true;
	}
} // namespace Pazu

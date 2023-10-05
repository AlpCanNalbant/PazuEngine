// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Transform.h"
#include "TransformBase.h"

namespace Pazu
{
	Matrix TransformBase::GetMatrix() const
	{
		if (m_parent)
			return m_matrix * m_parent->GetMatrix();
		return m_matrix;
	}

	bool TransformBase::GetDirty() const
	{
		return m_dirty;
	}

	void TransformBase::SetMatrix(const Matrix &matrix)
	{
		m_matrix = matrix;
	}

	void TransformBase::SetDirty(const bool dirty)
	{
		m_dirty = dirty;
	}
} // namespace Pazu

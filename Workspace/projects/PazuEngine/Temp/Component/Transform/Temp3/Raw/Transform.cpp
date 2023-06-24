#include "Transform.h"

namespace Pazu
{
	Transform::Transform() noexcept
			: m_hierarchy(this) {}

	Matrix Transform::GetMatrix() const noexcept
	{
		if (m_hierarchy.GetParent())
			return m_matrix * m_hierarchy.GetParent()->GetMatrix();
		return m_matrix;
	}

	bool Transform::GetDirty() const noexcept
	{
		return m_dirty;
	}

	Hierarchy<Transform> &Transform::GetHierarchy() noexcept
	{
		return m_hierarchy;
	}

	void Transform::SetMatrix(const Matrix &matrix) noexcept
	{
		m_matrix = matrix;
	}

	void Transform::SetDirty(const bool dirty) noexcept
	{
		m_dirty = dirty;
	}
} // namespace Pazu

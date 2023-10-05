// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TransformComponent.h"

namespace Pazu
{
	TransformComponent::TransformComponent() noexcept
		: m_hierarchy(this) {}

	Matrix TransformComponent::GetMatrix() const noexcept
	{
		if (m_hierarchy.GetParent())
			return m_matrix * m_hierarchy.GetParent()->GetMatrix();
		return m_matrix;
	}

	bool TransformComponent::GetDirty() const noexcept
	{
		return m_dirty;
	}

	Hierarchy<TransformComponent> &TransformComponent::GetHierarchy() noexcept
	{
		return m_hierarchy;
	}

	void TransformComponent::SetMatrix(const Matrix &matrix) noexcept
	{
		m_matrix = matrix;
	}

	void TransformComponent::SetDirty(const bool dirty) noexcept
	{
		m_dirty = dirty;
	}
} // namespace Pazu

#pragma once
#include "../../Math/Matrix.h"
#include "../../Math/Vector3.h"
#include "../../Tools/Hierarchy.h"
#include "../IComponent.h"

namespace Pazu
{
	class TransformComponent : public IComponent
	{
	public:
		TransformComponent() noexcept;
		Matrix GetMatrix() const noexcept;
		bool GetDirty() const noexcept;
		Hierarchy<TransformComponent> &GetHierarchy() noexcept;
		void SetMatrix(const Matrix &matrix) noexcept;
		void SetDirty(const bool dirty) noexcept;

	protected:
		Hierarchy<TransformComponent> m_hierarchy;
		Matrix m_matrix;
		bool m_dirty{false};
	};
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Math/Matrix.h"
#include "../../../Math/Vector3.h"
#include "../../../Tools/Hierarchy.h"

namespace Pazu
{
	class Transform
	{
	public:
		Transform() noexcept;
		virtual ~Transform() noexcept = default;
		Transform(const Transform &other) noexcept = default;
		Transform(Transform &&other) noexcept = default;
		Transform &operator=(const Transform &other) noexcept = default;
		Transform &operator=(Transform &&other) noexcept = default;
		Matrix GetMatrix() const noexcept;
		bool GetDirty() const noexcept;
		Hierarchy<Transform> &GetHierarchy() noexcept;
		void SetMatrix(const Matrix &matrix) noexcept;
		void SetDirty(const bool dirty) noexcept;

	protected:
		Hierarchy<Transform> m_hierarchy;
		Matrix m_matrix;
		bool m_dirty{false};
	};
} // namespace Pazu

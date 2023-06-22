#pragma once
#include "../Quaternion.h"
#include "../Matrix.h"
#include "../Vector3.h"

namespace Pazu
{
	class Transform;
	class TransformBase
	{
	public:
		TransformBase() = default;
		virtual ~TransformBase() = default;
		TransformBase(const TransformBase &other) = default;
		TransformBase(TransformBase &&other) = default;
		TransformBase &operator=(const TransformBase &other) = default;
		TransformBase &operator=(TransformBase &&other) = default;
		Matrix GetMatrix() const;
		bool GetDirty() const;
		void SetMatrix(const Matrix &matrix);
		void SetDirty(const bool dirty);

	protected:
		Matrix m_matrix;
		bool m_dirty{false};
		Transform *m_parent{nullptr};
	};
} // namespace Pazu

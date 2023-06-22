#pragma once
#include "../../Math/Matrix.h"
#include "../IComponent.h"

namespace Pazu
{
	class CameraComponent : public IComponent
	{
	public:
		virtual void CalculateProjection() = 0;
		const Matrix &GetProjection() const;
		bool GetDirty() const;
		const Size &GetViewSize() const;
		float GetNear() const;
		float GetFar() const;
		void SetProjection(const Matrix &projection);
		void SetDirty(const bool dirty);
		void SetViewSize(const Size &viewSize);
		void SetNear(const float nearAmount);
		void SetFar(const float farAmount);

	protected:
		Matrix m_projection;
		Size m_viewSize{Size::One};
		float m_near{0.1f}, m_far;
		bool m_dirty{false};
	};
} // namespace Pazu

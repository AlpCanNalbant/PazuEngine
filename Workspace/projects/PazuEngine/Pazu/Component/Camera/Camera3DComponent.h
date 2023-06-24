#pragma once
#include "CameraComponent.h"

namespace Pazu
{
	class Camera3DComponent : public CameraComponent
	{
	public:
		Camera3DComponent();
		void CalculateProjection() final;
		float GetFov() const;
		void SetFov(const float fov);

	private:
		float m_fov{45.f};
	};
} // namespace Pazu

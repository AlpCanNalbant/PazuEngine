#pragma once
#include "../../../Math/Quaternion.h"
#include "Transform.h"

namespace Pazu
{
	class TransformRotation : public virtual Transform
	{
	public:
		Matrix CreateRotation() noexcept;
		void Rotate(const Vector3 &rotation, const bool global = false) noexcept;
		void Rotate(const float pitch, const float yaw, const float roll, const bool global = false) noexcept;
		void Rotate(const Vector3 &axis, const float angle, const bool global = false) noexcept;
		const Vector3 &GetRotation() const noexcept;
		float GetPitch() const noexcept;
		float GetYaw() const noexcept;
		float GetRoll() const noexcept;
		void SetRotation(const Vector3 &rotation, const bool global = false) noexcept;
		void SetRotation(const float pitch, const float yaw, const float roll, const bool global = false) noexcept;
		void SetRotation(const Vector3 &axis, const float angle, const bool global = false) noexcept;
		void SetPitch(const float pitch, const bool global = false) noexcept;
		void SetYaw(const float yaw, const bool global = false) noexcept;
		void SetRoll(const float roll, const bool global = false) noexcept;

	protected:
		Quaternion m_rotation;
		Vector3 m_eulerAngles;
	};
} // namespace Pazu

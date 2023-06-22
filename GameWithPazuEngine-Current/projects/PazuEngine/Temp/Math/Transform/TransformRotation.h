#pragma once
#include "TransformBase.h"

namespace Pazu
{
	class TransformRotation : public virtual TransformBase
	{
	public:
		void CalculateRotation();
		void Rotate(const Vector3 &rotation, const bool global = false);
		void Rotate(const float pitch, const float yaw, const float roll, const bool global = false);
		void Rotate(const Vector3 &axis, const float angle, const bool global = false);
		const Vector3 &GetRotation() const;
		const Quaternion &GetQuaternion() const;
		float GetPitch() const;
		float GetYaw() const;
		float GetRoll() const;
		void SetRotation(const Vector3 &rotation, const bool global = false);
		void SetRotation(const float pitch, const float yaw, const float roll, const bool global = false);
		void SetRotation(const Vector3 &axis, const float angle, const bool global = false);
		void SetQuaternion(const Quaternion &quaternion);
		void SetPitch(const float pitch, const bool global = false);
		void SetYaw(const float yaw, const bool global = false);
		void SetRoll(const float roll, const bool global = false);

	protected:
		Quaternion m_quaternion;
		Vector3 m_rotation;
	};
} // namespace Pazu

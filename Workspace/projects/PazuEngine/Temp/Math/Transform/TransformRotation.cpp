// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../Vector2.h"
#include "TransformRotation.h"

namespace Pazu
{
	void TransformRotation::CalculateRotation()
	{
		m_matrix = Matrix::CreateFromQuaternion(m_quaternion);
	}

	void TransformRotation::Rotate(const Vector3 &rotation, const bool global)
	{
		if (!global)
		{
			const auto localRot = Vector3::Transform(rotation, m_quaternion);
			m_quaternion *= Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(localRot.y), Mathf::ToRadians(localRot.x), Mathf::ToRadians(localRot.z));
			m_rotation += localRot;
		}
		else
		{
			m_quaternion *= Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(rotation.y), Mathf::ToRadians(rotation.x), Mathf::ToRadians(rotation.z));
			m_rotation += rotation;
		}
		m_dirty = true;
	}

	void TransformRotation::Rotate(const float pitch, const float yaw, const float roll, const bool global)
	{
		Rotate({pitch, yaw, roll}, global);
	}

	void TransformRotation::Rotate(const Vector3 &axis, const float angle, const bool global)
	{
		if (!global)
		{
			const auto localAxis = Vector3::Transform(axis, m_quaternion);
			m_quaternion *= Quaternion::CreateFromAxisAngle(localAxis, Mathf::ToRadians(angle));
			m_rotation += localAxis * angle;
		}
		else
		{
			m_quaternion *= Quaternion::CreateFromAxisAngle(axis, Mathf::ToRadians(angle));
			m_rotation += axis * angle;
		}
		m_dirty = true;
	}

	const Vector3 &TransformRotation::GetRotation() const
	{
		return m_rotation;
	}

	const Quaternion &TransformRotation::GetQuaternion() const
	{
		return m_quaternion;
	}

	float TransformRotation::GetPitch() const
	{
		return m_rotation.x;
	}

	float TransformRotation::GetYaw() const
	{
		return m_rotation.y;
	}

	float TransformRotation::GetRoll() const
	{
		return m_rotation.z;
	}

	void TransformRotation::SetRotation(const Vector3 &rotation, const bool global)
	{
		if (!global)
		{
			const auto localRot = Vector3::Transform(rotation, m_quaternion);
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(localRot.y), Mathf::ToRadians(localRot.x), Mathf::ToRadians(localRot.z));
			m_rotation = localRot;
		}
		else
		{
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(rotation.y), Mathf::ToRadians(rotation.x), Mathf::ToRadians(rotation.z));
			m_rotation = rotation;
		}
		m_dirty = true;
	}

	void TransformRotation::SetRotation(const float pitch, const float yaw, const float roll, const bool global)
	{
		SetRotation({pitch, yaw, roll}, global);
	}

	void TransformRotation::SetRotation(const Vector3 &axis, const float angle, const bool global)
	{
		if (!global)
		{
			const auto localAxis = Vector3::Transform(axis, m_quaternion);
			m_quaternion = Quaternion::CreateFromAxisAngle(localAxis, Mathf::ToRadians(angle));
			m_rotation = localAxis * angle;
		}
		else
		{
			m_quaternion = Quaternion::CreateFromAxisAngle(axis, Mathf::ToRadians(angle));
			m_rotation = axis * angle;
		}
		m_dirty = true;
	}

	void TransformRotation::SetQuaternion(const Quaternion &quaternion)
	{
		m_quaternion = quaternion;
	}

	void TransformRotation::SetPitch(const float pitch, const bool global)
	{
		if (!global)
		{
			const auto localPitch = Vector2::Transform({pitch, 0.f}, m_quaternion).x;
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_rotation.y), Mathf::ToRadians(localPitch), Mathf::ToRadians(m_rotation.z));
			m_rotation.x = localPitch;
		}
		else
		{
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_rotation.y), Mathf::ToRadians(pitch), Mathf::ToRadians(m_rotation.z));
			m_rotation.x = pitch;
		}
		m_dirty = true;
	}

	void TransformRotation::SetYaw(const float yaw, const bool global)
	{
		if (!global)
		{
			const auto localYaw = Vector2::Transform({yaw, 0.f}, m_quaternion).x;
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(localYaw), Mathf::ToRadians(m_rotation.x), Mathf::ToRadians(m_rotation.z));
			m_rotation.y = localYaw;
		}
		else
		{
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(yaw), Mathf::ToRadians(m_rotation.x), Mathf::ToRadians(m_rotation.z));
			m_rotation.y = yaw;
		}
		m_dirty = true;
	}

	void TransformRotation::SetRoll(const float roll, const bool global)
	{
		if (!global)
		{
			const auto localRoll = Vector2::Transform({roll, 0.f}, m_quaternion).x;
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_rotation.x), Mathf::ToRadians(m_rotation.x), Mathf::ToRadians(localRoll));
			m_rotation.z = localRoll;
		}
		else
		{
			m_quaternion = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_rotation.y), Mathf::ToRadians(m_rotation.x), Mathf::ToRadians(roll));
			m_rotation.z = roll;
		}
		m_dirty = true;
	}
}

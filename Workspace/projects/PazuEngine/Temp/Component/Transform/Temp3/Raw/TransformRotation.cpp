// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../../../Math/Vector2.h"
#include "TransformRotation.h"

namespace Pazu
{
	Matrix TransformRotation::CreateRotation() noexcept
	{
		return Matrix::CreateFromQuaternion(m_rotation);
	}

	void TransformRotation::Rotate(const Vector3 &rotation, const bool global) noexcept
	{
		if (!global)
		{
			const auto localRot = Vector3::Transform(rotation, m_rotation);
			m_rotation *= Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(localRot.y), Mathf::ToRadians(localRot.x), Mathf::ToRadians(localRot.z));
			m_eulerAngles += localRot;
		}
		else
		{
			m_rotation *= Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(rotation.y), Mathf::ToRadians(rotation.x), Mathf::ToRadians(rotation.z));
			m_eulerAngles += rotation;
		}
		m_dirty = true;
	}

	void TransformRotation::Rotate(const float pitch, const float yaw, const float roll, const bool global) noexcept
	{
		Rotate({pitch, yaw, roll}, global);
	}

	void TransformRotation::Rotate(const Vector3 &axis, const float angle, const bool global) noexcept
	{
		if (!global)
		{
			const auto localAxis = Vector3::Transform(axis, m_rotation);
			m_rotation *= Quaternion::CreateFromAxisAngle(localAxis, Mathf::ToRadians(angle));
			m_eulerAngles += localAxis * angle;
		}
		else
		{
			m_rotation *= Quaternion::CreateFromAxisAngle(axis, Mathf::ToRadians(angle));
			m_eulerAngles += axis * angle;
		}
		m_dirty = true;
	}

	const Vector3 &TransformRotation::GetRotation() const noexcept
	{
		return m_eulerAngles;
	}

	float TransformRotation::GetPitch() const noexcept
	{
		return m_eulerAngles.x;
	}

	float TransformRotation::GetYaw() const noexcept
	{
		return m_eulerAngles.y;
	}

	float TransformRotation::GetRoll() const noexcept
	{
		return m_eulerAngles.z;
	}

	void TransformRotation::SetRotation(const Vector3 &rotation, const bool global) noexcept
	{
		if (!global)
		{
			const auto localRot = Vector3::Transform(rotation, m_rotation);
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(localRot.y), Mathf::ToRadians(localRot.x), Mathf::ToRadians(localRot.z));
			m_eulerAngles = localRot;
		}
		else
		{
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(rotation.y), Mathf::ToRadians(rotation.x), Mathf::ToRadians(rotation.z));
			m_eulerAngles = rotation;
		}
		m_dirty = true;
	}

	void TransformRotation::SetRotation(const float pitch, const float yaw, const float roll, const bool global) noexcept
	{
		SetRotation({pitch, yaw, roll}, global);
	}

	void TransformRotation::SetRotation(const Vector3 &axis, const float angle, const bool global) noexcept
	{
		if (!global)
		{
			const auto localAxis = Vector3::Transform(axis, m_rotation);
			m_rotation = Quaternion::CreateFromAxisAngle(localAxis, Mathf::ToRadians(angle));
			m_eulerAngles = localAxis * angle;
		}
		else
		{
			m_rotation = Quaternion::CreateFromAxisAngle(axis, Mathf::ToRadians(angle));
			m_eulerAngles = axis * angle;
		}
		m_dirty = true;
	}

	void TransformRotation::SetPitch(const float pitch, const bool global) noexcept
	{
		if (!global)
		{
			const auto localPitch = Vector2::Transform({pitch, 0.f}, m_rotation).x;
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_eulerAngles.y), Mathf::ToRadians(localPitch), Mathf::ToRadians(m_eulerAngles.z));
			m_eulerAngles.x = localPitch;
		}
		else
		{
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_eulerAngles.y), Mathf::ToRadians(pitch), Mathf::ToRadians(m_eulerAngles.z));
			m_eulerAngles.x = pitch;
		}
		m_dirty = true;
	}

	void TransformRotation::SetYaw(const float yaw, const bool global) noexcept
	{
		if (!global)
		{
			const auto localYaw = Vector2::Transform({yaw, 0.f}, m_rotation).x;
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(localYaw), Mathf::ToRadians(m_eulerAngles.x), Mathf::ToRadians(m_eulerAngles.z));
			m_eulerAngles.y = localYaw;
		}
		else
		{
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(yaw), Mathf::ToRadians(m_eulerAngles.x), Mathf::ToRadians(m_eulerAngles.z));
			m_eulerAngles.y = yaw;
		}
		m_dirty = true;
	}

	void TransformRotation::SetRoll(const float roll, const bool global) noexcept
	{
		if (!global)
		{
			const auto localRoll = Vector2::Transform({roll, 0.f}, m_rotation).x;
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_eulerAngles.x), Mathf::ToRadians(m_eulerAngles.x), Mathf::ToRadians(localRoll));
			m_eulerAngles.z = localRoll;
		}
		else
		{
			m_rotation = Quaternion::CreateFromYawPitchRoll(Mathf::ToRadians(m_eulerAngles.y), Mathf::ToRadians(m_eulerAngles.x), Mathf::ToRadians(roll));
			m_eulerAngles.z = roll;
		}
		m_dirty = true;
	}
}

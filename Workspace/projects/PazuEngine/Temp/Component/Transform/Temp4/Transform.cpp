#include "Vector2.h"
#include "Transform.h"

namespace Pazu
{
	Transform::Transform() noexcept
			: m_hierarchy(this) {}

	Matrix Transform::CreateTranslation() noexcept
	{
		return Matrix::CreateTranslation(m_position);
	}

	Matrix Transform::CreateRotation() noexcept
	{
		return Matrix::CreateFromQuaternion(m_rotation);
	}

	Matrix Transform::CreateLookAt() noexcept
	{
		const auto rotMat = CreateRotation();
		return Matrix::CreateLookAt(m_position, m_position + rotMat.Forward(), rotMat.Up());
	}

	Matrix Transform::CreateScale() noexcept
	{
		return Matrix::CreateScale(m_scale);
	}

	void Transform::Translate(const Vector3 &position, const bool global) noexcept
	{
		if (!global)
			m_position += Vector3::Transform(position, m_rotation);
		else
			m_position += position;
		m_dirty = true;
	}

	void Transform::Translate(const float x, const float y, const float z, const bool global) noexcept
	{
		Translate({x, y, z}, global);
	}

	void Transform::Rotate(const Vector3 &rotation, const bool global) noexcept
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

	void Transform::Rotate(const float pitch, const float yaw, const float roll, const bool global) noexcept
	{
		Rotate({pitch, yaw, roll}, global);
	}

	void Transform::Rotate(const Vector3 &axis, const float angle, const bool global) noexcept
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

	void Transform::Scale(const Vector3 &scale) noexcept
	{
		m_scale += scale;
		m_dirty = true;
	}

	void Transform::Scale(const float width, const float height, const float depth) noexcept
	{
		Scale({width, height, depth});
	}

	void Transform::Scale(const float scale) noexcept
	{
		Scale({scale, scale, scale});
	}

	const Vector3 &Transform::GetPosition() const noexcept
	{
		return m_position;
	}

	float Transform::GetX() const noexcept
	{
		return m_position.x;
	}

	float Transform::GetY() const noexcept
	{
		return m_position.y;
	}

	float Transform::GetZ() const noexcept
	{
		return m_position.z;
	}

	const Vector3 &Transform::GetRotation() const noexcept
	{
		return m_eulerAngles;
	}

	float Transform::GetPitch() const noexcept
	{
		return m_eulerAngles.x;
	}

	float Transform::GetYaw() const noexcept
	{
		return m_eulerAngles.y;
	}

	float Transform::GetRoll() const noexcept
	{
		return m_eulerAngles.z;
	}

	const Vector3 &Transform::GetScale() const noexcept
	{
		return m_scale;
	}

	float Transform::GetWidth() const noexcept
	{
		return m_scale.x;
	}

	float Transform::GetHeight() const noexcept
	{
		return m_scale.y;
	}

	float Transform::GetDepth() const noexcept
	{
		return m_scale.z;
	}

	Matrix Transform::GetMatrix() const noexcept
	{
		if (m_hierarchy.GetParent())
			return m_matrix * m_hierarchy.GetParent()->GetMatrix();
		return m_matrix;
	}

	bool Transform::GetDirty() const noexcept
	{
		return m_dirty;
	}

	Hierarchy<Transform> &Transform::GetHierarchy() noexcept
	{
		return m_hierarchy;
	}

	void Transform::SetPosition(const Vector3 &position, const bool global) noexcept
	{
		if (!global)
			m_position = Vector3::Transform(position, m_rotation);
		else
			m_position = position;
		m_dirty = true;
	}

	void Transform::SetPosition(const float x, const float y, const float z, const bool global) noexcept
	{
		SetPosition({x, y, z}, global);
	}

	void Transform::SetX(const float x, const bool global) noexcept
	{
		if (!global)
			m_position.x = Vector2::Transform({x, 0.f}, m_rotation).x;
		else
			m_position.x = x;
		m_dirty = true;
	}

	void Transform::SetY(const float y, const bool global) noexcept
	{
		if (!global)
			m_position.y = Vector2::Transform({y, 0.f}, m_rotation).x;
		else
			m_position.y = y;
		m_dirty = true;
	}

	void Transform::SetZ(const float z, const bool global) noexcept
	{
		if (!global)
			m_position.z = Vector2::Transform({z, 0.f}, m_rotation).x;
		else
			m_position.z = z;
		m_dirty = true;
	}

	void Transform::SetRotation(const Vector3 &rotation, const bool global) noexcept
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

	void Transform::SetRotation(const float pitch, const float yaw, const float roll, const bool global) noexcept
	{
		SetRotation({pitch, yaw, roll}, global);
	}

	void Transform::SetRotation(const Vector3 &axis, const float angle, const bool global) noexcept
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

	void Transform::SetPitch(const float pitch, const bool global) noexcept
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

	void Transform::SetYaw(const float yaw, const bool global) noexcept
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

	void Transform::SetRoll(const float roll, const bool global) noexcept
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

	void Transform::SetScale(const Vector3 &scale) noexcept
	{
		m_scale = scale;
		m_dirty = true;
	}

	void Transform::SetScale(const float width, const float height, const float depth) noexcept
	{
		SetScale({width, height, depth});
	}

	void Transform::SetScale(const float scale) noexcept
	{
		SetScale({scale, scale, scale});
	}

	void Transform::SetWidth(const float width) noexcept
	{
		m_scale.x = width;
		m_dirty = true;
	}

	void Transform::SetHeight(const float height) noexcept
	{
		m_scale.y = height;
		m_dirty = true;
	}

	void Transform::SetDepth(const float depth) noexcept
	{
		m_scale.z = depth;
		m_dirty = true;
	}

	void Transform::SetMatrix(const Matrix &matrix) noexcept
	{
		m_matrix = matrix;
	}

	void Transform::SetDirty(const bool dirty) noexcept
	{
		m_dirty = dirty;
	}
} // namespace Pazu

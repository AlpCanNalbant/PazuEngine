#include "Vector2.h"
#include "Transform.h"

namespace Pazu
{
	Transform::~Transform()
	{
		RemoveParent();
		RemoveChildren(true);
	}

	Transform::Transform(const Transform &other)
			: m_position(other.m_position), m_quaternion(other.m_quaternion), m_rotation(other.m_rotation), m_scale(other.m_scale), m_matrix(other.m_matrix) {}

	Transform &Transform::operator=(const Transform &other)
	{
		m_position = other.m_position;
		m_quaternion = other.m_quaternion;
		m_rotation = other.m_rotation;
		m_scale = other.m_scale;
		m_matrix = other.m_matrix;
		return *this;
	}

	void Transform::CalculateWorld()
	{
		m_matrix = Matrix::CreateScale(m_scale) * Matrix::CreateFromQuaternion(m_quaternion) * Matrix::CreateTranslation(m_position);
	}

	void Transform::CalculateLookAt()
	{
		const auto rotMat = Matrix::CreateFromQuaternion(m_quaternion);
		m_matrix = Matrix::CreateLookAt(m_position, m_position + rotMat.Forward(), rotMat.Up());
	}

	void Transform::CalculateTranslation()
	{
		m_matrix = Matrix::CreateTranslation(m_position);
	}

	void Transform::CalculateRotation()
	{
		m_matrix = Matrix::CreateFromQuaternion(m_quaternion);
	}

	void Transform::CalculateScale()
	{
		m_matrix = Matrix::CreateScale(m_scale);
	}

	void Transform::Translate(const Vector3 &position, const bool global)
	{
		if (!global)
			m_position += Vector3::Transform(position, m_quaternion);
		else
			m_position += position;
		m_dirty = true;
	}

	void Transform::Translate(const float x, const float y, const float z, const bool global)
	{
		Translate({x, y, z}, global);
	}

	void Transform::Rotate(const Vector3 &rotation, const bool global)
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

	void Transform::Rotate(const float pitch, const float yaw, const float roll, const bool global)
	{
		Rotate({pitch, yaw, roll}, global);
	}

	void Transform::Rotate(const Vector3 &axis, const float angle, const bool global)
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

	void Transform::Scale(const Vector3 &scale)
	{
		m_scale += scale;
		m_dirty = true;
	}

	void Transform::Scale(const float width, const float height, const float depth)
	{
		Scale({width, height, depth});
	}

	void Transform::Scale(const float scale)
	{
		Scale({scale, scale, scale});
	}

	void Transform::AddChild(Transform &transform)
	{
		auto transformPtr = &transform;
		if (transformPtr == this && GetChildOf(transform))
			return Log::Get().Print<LogMode::Error>("Child eklenemedi. Cunku ayni veya parent.");

		if (std::find(m_children.cbegin(), m_children.cend(), transformPtr) != m_children.cend())
			return Log::Get().Print<LogMode::Error>("Child eklenemedi. Zaten mevcut.");

		transform.RemoveParent();
		transform.m_parent = this;
		m_children.emplace_back(transformPtr);
	}

	void Transform::RemoveChild(Transform &transform)
	{
		if (m_children.empty())
			return Log::Get().Print<LogMode::Error>("Child silinemedi. Icerik bos.");

		auto transformPtr = &transform;
		const auto pos = std::find(m_children.cbegin(), m_children.cend(), transformPtr);
		if (pos == m_children.cend())
			return Log::Get().Print<LogMode::Error>("Child silinemedi. Mevcut degil.");

		m_children.erase(pos);
		transform.m_parent = nullptr;
	}

	void Transform::RemoveChildren(const bool recursive)
	{
		if (m_children.empty())
			return;

		for (auto child : m_children)
		{
			RemoveChild(*child);
			if (recursive)
				child->RemoveChildren(true);
		}
	}

	void Transform::RemoveParent()
	{
		if (m_parent)
			m_parent->RemoveChild(*this);
	}

	const Vector3 &Transform::GetPosition() const
	{
		return m_position;
	}

	const Vector3 &Transform::GetRotation() const
	{
		return m_rotation;
	}

	const Quaternion &Transform::GetQuaternion() const
	{
		return m_quaternion;
	}

	const Vector3 &Transform::GetScale() const
	{
		return m_scale;
	}

	float Transform::GetX() const
	{
		return m_position.x;
	}

	float Transform::GetY() const
	{
		return m_position.y;
	}

	float Transform::GetZ() const
	{
		return m_position.z;
	}

	float Transform::GetPitch() const
	{
		return m_rotation.x;
	}

	float Transform::GetYaw() const
	{
		return m_rotation.y;
	}

	float Transform::GetRoll() const
	{
		return m_rotation.z;
	}

	float Transform::GetWidth() const
	{
		return m_scale.x;
	}

	float Transform::GetHeight() const
	{
		return m_scale.y;
	}

	float Transform::GetDepth() const
	{
		return m_scale.z;
	}

	Matrix Transform::GetMatrix() const
	{
		if (m_parent)
			return m_matrix * m_parent->GetMatrix();
		return m_matrix;
	}

	Transform *Transform::GetParent() const
	{
		return m_parent;
	}

	const std::vector<Transform *> &Transform::GetChildren() const
	{
		return m_children;
	}

	bool Transform::GetChildOf(Transform &parent) const
	{
		auto parentPtr = m_parent;
		while (parentPtr)
		{
			if (parentPtr == &parent)
				return true;
			parentPtr = parentPtr->m_parent;
		}

		return false;
	}

	bool Transform::GetDirty() const
	{
		return m_dirty;
	}

	void Transform::SetPosition(const Vector3 &position, const bool global)
	{
		if (!global)
			m_position = Vector3::Transform(position, m_quaternion);
		else
			m_position = position;
		m_dirty = true;
	}

	void Transform::SetPosition(const float x, const float y, const float z, const bool global)
	{
		SetPosition({x, y, z}, global);
	}

	void Transform::SetRotation(const Vector3 &rotation, const bool global)
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

	void Transform::SetRotation(const float pitch, const float yaw, const float roll, const bool global)
	{
		SetRotation({pitch, yaw, roll}, global);
	}

	void Transform::SetRotation(const Vector3 &axis, const float angle, const bool global)
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

	void Transform::SetQuaternion(const Quaternion &quaternion)
	{
		m_quaternion = quaternion;
	}

	void Transform::SetScale(const Vector3 &scale)
	{
		m_scale = scale;
		m_dirty = true;
	}

	void Transform::SetScale(const float width, const float height, const float depth)
	{
		SetScale({width, height, depth});
	}

	void Transform::SetScale(const float scale)
	{
		SetScale({scale, scale, scale});
	}

	void Transform::SetX(const float x, const bool global)
	{
		if (!global)
			m_position.x = Vector2::Transform({x, 0.f}, m_quaternion).x;
		else
			m_position.x = x;
		m_dirty = true;
	}

	void Transform::SetY(const float y, const bool global)
	{
		if (!global)
			m_position.y = Vector2::Transform({y, 0.f}, m_quaternion).x;
		else
			m_position.y = y;
		m_dirty = true;
	}

	void Transform::SetZ(const float z, const bool global)
	{
		if (!global)
			m_position.z = Vector2::Transform({z, 0.f}, m_quaternion).x;
		else
			m_position.z = z;
		m_dirty = true;
	}

	void Transform::SetPitch(const float pitch, const bool global)
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

	void Transform::SetYaw(const float yaw, const bool global)
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

	void Transform::SetRoll(const float roll, const bool global)
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

	void Transform::SetWidth(const float width)
	{
		m_scale.x = width;
		m_dirty = true;
	}

	void Transform::SetHeight(const float height)
	{
		m_scale.y = height;
		m_dirty = true;
	}

	void Transform::SetDepth(const float depth)
	{
		m_scale.z = depth;
		m_dirty = true;
	}

	void Transform::SetMatrix(const Matrix &matrix)
	{
		m_matrix = matrix;
	}

	void Transform::SetParent(Transform &parent)
	{
		if (m_parent == &parent)
			return Log::Get().Print<LogMode::Error>("Parent atanamadi. Zaten atanmis.");

		parent.AddChild(*this);
	}

	void Transform::SetDirty(const bool dirty)
	{
		m_dirty = dirty;
	}
}

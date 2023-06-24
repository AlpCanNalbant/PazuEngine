#pragma once
#include "Quaternion.h"
#include "Matrix.h"
#include "Vector3.h"

namespace Pazu
{
	class Transform
	{
	public:
		Transform() = default;
		~Transform();
		Transform(const Transform &other);
		Transform(Transform &&other) = default;
		Transform &operator=(const Transform &other);
		Transform &operator=(Transform &&other) = default;
		void CalculateWorld();
		void CalculateLookAt();
		void CalculateTranslation();
		void CalculateRotation();
		void CalculateScale();
		void Translate(const Vector3 &position, const bool global = false);
		void Translate(const float x, const float y, const float z, const bool global = false);
		void Rotate(const Vector3 &rotation, const bool global = false);
		void Rotate(const float pitch, const float yaw, const float roll, const bool global = false);
		void Rotate(const Vector3 &axis, const float angle, const bool global = false);
		void Scale(const Vector3 &scale);
		void Scale(const float width, const float height, const float depth);
		void Scale(const float scale);
		void AddChild(Transform &transform);
		void RemoveChild(Transform &transform);
		void RemoveChildren(const bool recursive = false);
		void RemoveParent();
		const Vector3 &GetPosition() const;
		const Vector3 &GetRotation() const;
		const Quaternion &GetQuaternion() const;
		const Vector3 &GetScale() const;
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetPitch() const;
		float GetYaw() const;
		float GetRoll() const;
		float GetWidth() const;
		float GetHeight() const;
		float GetDepth() const;
		Matrix GetMatrix() const;
		Transform *GetParent() const;
		const std::vector<Transform *> &GetChildren() const;
		bool GetChildOf(Transform &parent) const;
		bool GetDirty() const;
		void SetPosition(const Vector3 &position, const bool global = false);
		void SetPosition(const float x, const float y, const float z, const bool global = false);
		void SetRotation(const Vector3 &rotation, const bool global = false);
		void SetRotation(const float pitch, const float yaw, const float roll, const bool global = false);
		void SetRotation(const Vector3 &axis, const float angle, const bool global = false);
		void SetQuaternion(const Quaternion &quaternion);
		void SetScale(const Vector3 &scale);
		void SetScale(const float width, const float height, const float depth);
		void SetScale(const float scale);
		void SetX(const float x, const bool global = false);
		void SetY(const float y, const bool global = false);
		void SetZ(const float z, const bool global = false);
		void SetPitch(const float pitch, const bool global = false);
		void SetYaw(const float yaw, const bool global = false);
		void SetRoll(const float roll, const bool global = false);
		void SetWidth(const float width);
		void SetHeight(const float height);
		void SetDepth(const float depth);
		void SetMatrix(const Matrix &matrix);
		void SetParent(Transform &parent);
		void SetDirty(const bool dirty);

	private:
		Vector3 m_position;
		Quaternion m_quaternion;
		Vector3 m_rotation;
		Vector3 m_scale{Vector3::One};
		Matrix m_matrix;
		std::vector<Transform *> m_children;
		Transform *m_parent{nullptr};
		bool m_dirty{false};
	};
}

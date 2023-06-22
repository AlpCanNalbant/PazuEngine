#pragma once
#include "Quaternion.h"
#include "Matrix.h"
#include "Vector3.h"
#include "../Tools/Hierarchy.h"

namespace Pazu
{
	class Transform
	{
	public:
		Transform() noexcept;
		Matrix CreateTranslation() noexcept;
		Matrix CreateRotation() noexcept;
		Matrix CreateLookAt() noexcept;
		Matrix CreateScale() noexcept;
		void Translate(const Vector3 &position, const bool global = false) noexcept;
		void Translate(const float x, const float y, const float z, const bool global = false) noexcept;
		void Rotate(const Vector3 &rotation, const bool global = false) noexcept;
		void Rotate(const float pitch, const float yaw, const float roll, const bool global = false) noexcept;
		void Rotate(const Vector3 &axis, const float angle, const bool global = false) noexcept;
		void Scale(const Vector3 &scale) noexcept;
		void Scale(const float width, const float height, const float depth) noexcept;
		void Scale(const float scale) noexcept;
		const Vector3 &GetPosition() const noexcept;
		float GetX() const noexcept;
		float GetY() const noexcept;
		float GetZ() const noexcept;
		const Vector3 &GetRotation() const noexcept;
		float GetPitch() const noexcept;
		float GetYaw() const noexcept;
		float GetRoll() const noexcept;
		const Vector3 &GetScale() const noexcept;
		float GetWidth() const noexcept;
		float GetHeight() const noexcept;
		float GetDepth() const noexcept;
		Matrix GetMatrix() const noexcept;
		bool GetDirty() const noexcept;
		Hierarchy<Transform> &GetHierarchy() noexcept;
		void SetPosition(const Vector3 &position, const bool global = false) noexcept;
		void SetPosition(const float x, const float y, const float z, const bool global = false) noexcept;
		void SetX(const float x, const bool global = false) noexcept;
		void SetY(const float y, const bool global = false) noexcept;
		void SetZ(const float z, const bool global = false) noexcept;
		void SetRotation(const Vector3 &rotation, const bool global = false) noexcept;
		void SetRotation(const float pitch, const float yaw, const float roll, const bool global = false) noexcept;
		void SetRotation(const Vector3 &axis, const float angle, const bool global = false) noexcept;
		void SetPitch(const float pitch, const bool global = false) noexcept;
		void SetYaw(const float yaw, const bool global = false) noexcept;
		void SetRoll(const float roll, const bool global = false) noexcept;
		void SetScale(const Vector3 &scale) noexcept;
		void SetScale(const float width, const float height, const float depth) noexcept;
		void SetScale(const float scale) noexcept;
		void SetWidth(const float width) noexcept;
		void SetHeight(const float height) noexcept;
		void SetDepth(const float depth) noexcept;
		void SetMatrix(const Matrix &matrix) noexcept;
		void SetDirty(const bool dirty) noexcept;

	private:
		Vector3 m_position;
		Quaternion m_rotation;
		Vector3 m_eulerAngles;
		Vector3 m_scale{Vector3::One};
		Hierarchy<Transform> m_hierarchy;
		Matrix m_matrix;
		bool m_dirty{false};
	};
} // namespace Pazu

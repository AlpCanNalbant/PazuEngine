#include "../../Math/Vector2.h"
#include "TransformPositionRotationComponent.h"

namespace Pazu
{
	Matrix TransformPositionRotationComponent::CreateLookAt() noexcept
	{
		const auto rotMat = CreateRotation();
		return Matrix::CreateLookAt(m_position, m_position + rotMat.Forward(), rotMat.Up());
	}

	void TransformPositionRotationComponent::Translate(const Vector3 &position, const bool global) noexcept
	{
		if (!global)
			m_position += Vector3::Transform(position, m_rotation);
		else
			m_position += position;
		m_dirty = true;
	}

	void TransformPositionRotationComponent::Translate(const float x, const float y, const float z, const bool global) noexcept
	{
		Translate({x, y, z}, global);
	}

	void TransformPositionRotationComponent::SetPosition(const Vector3 &position, const bool global) noexcept
	{
		if (!global)
			m_position = Vector3::Transform(position, m_rotation);
		else
			m_position = position;
		m_dirty = true;
	}

	void TransformPositionRotationComponent::SetPosition(const float x, const float y, const float z, const bool global) noexcept
	{
		SetPosition({x, y, z}, global);
	}

	void TransformPositionRotationComponent::SetX(const float x, const bool global) noexcept
	{
		if (!global)
			m_position.x = Vector2::Transform({x, 0.f}, m_rotation).x;
		else
			m_position.x = x;
		m_dirty = true;
	}

	void TransformPositionRotationComponent::SetY(const float y, const bool global) noexcept
	{
		if (!global)
			m_position.y = Vector2::Transform({y, 0.f}, m_rotation).x;
		else
			m_position.y = y;
		m_dirty = true;
	}

	void TransformPositionRotationComponent::SetZ(const float z, const bool global) noexcept
	{
		if (!global)
			m_position.z = Vector2::Transform({z, 0.f}, m_rotation).x;
		else
			m_position.z = z;
		m_dirty = true;
	}
}

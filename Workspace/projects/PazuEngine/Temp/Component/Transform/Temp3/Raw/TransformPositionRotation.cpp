// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../../../Math/Vector2.h"
#include "TransformPositionRotation.h"

namespace Pazu
{
	Matrix TransformPositionRotation::CreateLookAt() noexcept
	{
		const auto rotMat = CreateRotation();
		return Matrix::CreateLookAt(m_position, m_position + rotMat.Forward(), rotMat.Up());
	}

	void TransformPositionRotation::Translate(const Vector3 &position, const bool global) noexcept
	{
		if (!global)
			m_position += Vector3::Transform(position, m_rotation);
		else
			m_position += position;
		m_dirty = true;
	}

	void TransformPositionRotation::Translate(const float x, const float y, const float z, const bool global) noexcept
	{
		Translate({x, y, z}, global);
	}

	void TransformPositionRotation::SetPosition(const Vector3 &position, const bool global) noexcept
	{
		if (!global)
			m_position = Vector3::Transform(position, m_rotation);
		else
			m_position = position;
		m_dirty = true;
	}

	void TransformPositionRotation::SetPosition(const float x, const float y, const float z, const bool global) noexcept
	{
		SetPosition({x, y, z}, global);
	}

	void TransformPositionRotation::SetX(const float x, const bool global) noexcept
	{
		if (!global)
			m_position.x = Vector2::Transform({x, 0.f}, m_rotation).x;
		else
			m_position.x = x;
		m_dirty = true;
	}

	void TransformPositionRotation::SetY(const float y, const bool global) noexcept
	{
		if (!global)
			m_position.y = Vector2::Transform({y, 0.f}, m_rotation).x;
		else
			m_position.y = y;
		m_dirty = true;
	}

	void TransformPositionRotation::SetZ(const float z, const bool global) noexcept
	{
		if (!global)
			m_position.z = Vector2::Transform({z, 0.f}, m_rotation).x;
		else
			m_position.z = z;
		m_dirty = true;
	}
}

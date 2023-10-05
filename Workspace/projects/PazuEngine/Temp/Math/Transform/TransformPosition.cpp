// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../Vector2.h"
#include "TransformPosition.h"

namespace Pazu
{
	void TransformPosition::CalculateTranslation()
	{
		m_matrix = Matrix::CreateTranslation(m_position);
	}

	void TransformPosition::Translate(const Vector3 &position)
	{
		m_position += position;
		m_dirty = true;
	}

	void TransformPosition::Translate(const float x, const float y, const float z)
	{
		Translate({x, y, z});
	}

	const Vector3 &TransformPosition::GetPosition() const
	{
		return m_position;
	}

	float TransformPosition::GetX() const
	{
		return m_position.x;
	}

	float TransformPosition::GetY() const
	{
		return m_position.y;
	}

	float TransformPosition::GetZ() const
	{
		return m_position.z;
	}

	void TransformPosition::SetPosition(const Vector3 &position, const bool global)
	{
		if (!global)
			m_position = Vector3::Transform(position, m_quaternion);
		else
			m_position = position;
		m_dirty = true;
	}

	void TransformPosition::SetPosition(const float x, const float y, const float z, const bool global)
	{
		SetPosition({x, y, z}, global);
	}

	void TransformPosition::SetX(const float x, const bool global)
	{
		if (!global)
			m_position.x = Vector2::Transform({x, 0.f}, m_quaternion).x;
		else
			m_position.x = x;
		m_dirty = true;
	}

	void TransformPosition::SetY(const float y, const bool global)
	{
		if (!global)
			m_position.y = Vector2::Transform({y, 0.f}, m_quaternion).x;
		else
			m_position.y = y;
		m_dirty = true;
	}

	void TransformPosition::SetZ(const float z, const bool global)
	{
		if (!global)
			m_position.z = Vector2::Transform({z, 0.f}, m_quaternion).x;
		else
			m_position.z = z;
		m_dirty = true;
	}
} // namespace Pazu

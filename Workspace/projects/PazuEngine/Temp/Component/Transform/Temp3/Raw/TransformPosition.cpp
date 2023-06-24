#include "TransformPosition.h"

namespace Pazu
{
	Matrix TransformPosition::CreateTranslation() noexcept
	{
		return Matrix::CreateTranslation(m_position);
	}

	void TransformPosition::Translate(const Vector3 &position) noexcept
	{
		m_position += position;
		m_dirty = true;
	}

	void TransformPosition::Translate(const float x, const float y, const float z) noexcept
	{
		Translate({x, y, z});
	}

	const Vector3 &TransformPosition::GetPosition() const noexcept
	{
		return m_position;
	}

	float TransformPosition::GetX() const noexcept
	{
		return m_position.x;
	}

	float TransformPosition::GetY() const noexcept
	{
		return m_position.y;
	}

	float TransformPosition::GetZ() const noexcept
	{
		return m_position.z;
	}

	void TransformPosition::SetPosition(const Vector3 &position) noexcept
	{
		m_position = position;
		m_dirty = true;
	}

	void TransformPosition::SetPosition(const float x, const float y, const float z) noexcept
	{
		SetPosition({x, y, z});
	}

	void TransformPosition::SetX(const float x) noexcept
	{
		m_position.x = x;
		m_dirty = true;
	}

	void TransformPosition::SetY(const float y) noexcept
	{
		m_position.y = y;
		m_dirty = true;
	}

	void TransformPosition::SetZ(const float z) noexcept
	{
		m_position.z = z;
		m_dirty = true;
	}
} // namespace Pazu

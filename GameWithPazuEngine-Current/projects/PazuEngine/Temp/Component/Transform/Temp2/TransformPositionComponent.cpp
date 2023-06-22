#include "TransformPositionComponent.h"

namespace Pazu
{
	Matrix TransformPositionComponent::CreateTranslation() noexcept
	{
		return Matrix::CreateTranslation(m_position);
	}

	void TransformPositionComponent::Translate(const Vector3 &position) noexcept
	{
		m_position += position;
		m_dirty = true;
	}

	void TransformPositionComponent::Translate(const float x, const float y, const float z) noexcept
	{
		Translate({x, y, z});
	}

	const Vector3 &TransformPositionComponent::GetPosition() const noexcept
	{
		return m_position;
	}

	float TransformPositionComponent::GetX() const noexcept
	{
		return m_position.x;
	}

	float TransformPositionComponent::GetY() const noexcept
	{
		return m_position.y;
	}

	float TransformPositionComponent::GetZ() const noexcept
	{
		return m_position.z;
	}

	void TransformPositionComponent::SetPosition(const Vector3 &position) noexcept
	{
		m_position = position;
		m_dirty = true;
	}

	void TransformPositionComponent::SetPosition(const float x, const float y, const float z) noexcept
	{
		SetPosition({x, y, z});
	}

	void TransformPositionComponent::SetX(const float x) noexcept
	{
		m_position.x = x;
		m_dirty = true;
	}

	void TransformPositionComponent::SetY(const float y) noexcept
	{
		m_position.y = y;
		m_dirty = true;
	}

	void TransformPositionComponent::SetZ(const float z) noexcept
	{
		m_position.z = z;
		m_dirty = true;
	}
} // namespace Pazu

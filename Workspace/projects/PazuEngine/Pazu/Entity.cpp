#include "Entity.h"

namespace Pazu
{
	const Transform &Entity::GetTransform() const
	{
		return m_transform;
	}

	Transform &Entity::GetTransform()
	{
		return m_transform;
	}

	void Entity::SetTransform(const Transform &transform)
	{
		m_transform = transform;
	}
}

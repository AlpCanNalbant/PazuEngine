// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Bone.h"

namespace Pazu
{
	Bone::Bone(const std::string &name, const unsigned int id, const Matrix &offset, const Transform &transform)
		: m_name(name), m_id(id), m_offset(offset), m_transform(transform) {}

	const std::string &Bone::GetName() const
	{
		return m_name;
	}

	unsigned int Bone::GetId() const
	{
		return m_id;
	}

	const Matrix &Bone::GetOffset() const
	{
		return m_offset;
	}

	const Transform &Bone::GetTransform() const
	{
		return m_transform;
	}

	Transform &Bone::GetTransform()
	{
		return m_transform;
	}

	void Bone::SetTransform(const Transform &transform)
	{
		m_transform = transform;
	}
}

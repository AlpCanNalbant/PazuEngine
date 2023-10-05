// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Math/Transform.h"

namespace Pazu
{
	class Bone
	{
	public:
		Bone() = default;
		Bone(const std::string &name, const unsigned int id, const Matrix &offset, const Transform &transform = {});
		const std::string &GetName() const;
		unsigned int GetId() const;
		const Matrix &GetOffset() const;
		const Transform &GetTransform() const;
		Transform &GetTransform();
		void SetTransform(const Transform &transform);

	private:
		std::string m_name;
		unsigned int m_id;
		Matrix m_offset;
		Transform m_transform;
	};
}

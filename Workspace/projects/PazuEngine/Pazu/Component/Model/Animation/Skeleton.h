// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "Bone.h"

namespace Pazu
{
	class Skeleton
	{
	public:
		Skeleton() = default;
		Skeleton(std::initializer_list<Bone> bones);

		void Add(const Skeleton &skeleton);
		void Add(Skeleton &&skeleton);
		template <typename T>
			requires std::convertible_to<T, Bone>
		bool AddBone(T &&bone);
		void AddBones(std::vector<Bone> &&bones);

		std::optional<std::reference_wrapper<const Bone>> FindBone(const std::string &name) const;
		std::optional<std::reference_wrapper<Bone>> FindBone(const std::string &name);

	private:
		std::vector<Bone> bones_;
	};
}

#include "Skeleton.inl"

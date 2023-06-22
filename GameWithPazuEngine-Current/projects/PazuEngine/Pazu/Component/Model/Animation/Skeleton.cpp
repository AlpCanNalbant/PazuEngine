#include "Skeleton.h"

namespace Pazu
{
	Skeleton::Skeleton(std::initializer_list<Bone> bones)
			: bones_(bones) {}

	void Skeleton::Add(const Skeleton &skeleton)
	{
		std::ranges::for_each(skeleton.bones_, [this](const Bone &bone)
													{ AddBone(bone); });
	}

	void Skeleton::Add(Skeleton &&skeleton)
	{
		std::ranges::for_each(skeleton.bones_, [this](Bone &bone)
													{ AddBone(std::move(bone)); });
	}

	void Skeleton::AddBones(std::vector<Bone> &&bones)
	{
		std::ranges::for_each(bones, [this](Bone &bone)
													{ AddBone(std::move(bone)); });
	}

	std::optional<std::reference_wrapper<const Bone>> Skeleton::FindBone(const std::string &name) const
	{
		if (const auto pos = std::find_if(bones_.cbegin(), bones_.cend(), [&name](const auto &b)
																			{ return b.GetName() == name; });
				pos != bones_.cend())
		{
			return std::make_optional(std::cref(*pos));
		}

		return std::nullopt;
	}

	std::optional<std::reference_wrapper<Bone>> Skeleton::FindBone(const std::string &name)
	{
		if (auto pos = std::find_if(bones_.begin(), bones_.end(), [&name](const auto &b)
																{ return b.GetName() == name; });
				pos != bones_.cend())
		{
			return std::make_optional(std::ref(*pos));
		}

		return std::nullopt;
	}
}

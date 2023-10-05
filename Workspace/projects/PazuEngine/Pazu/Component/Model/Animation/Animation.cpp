// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Animation.h"

namespace Pazu
{
	Animation::Animation(const std::string &name, const std::unordered_map<std::string, std::vector<BoneFrame>> &boneFrames)
		: m_name(name), m_boneFrames(boneFrames) {}

	void Animation::AddBoneFrame(const std::string &boneName, const BoneFrame &boneFrame)
	{
		m_boneFrames[boneName].emplace_back(boneFrame);
	}

	void Animation::AddBoneFrames(const std::string &boneName, const std::vector<BoneFrame> &boneFrames)
	{
		if (!boneFrames.empty())
			m_boneFrames[boneName].insert(m_boneFrames.at(boneName).cend(), boneFrames.cbegin(), boneFrames.cend());
		else
			m_boneFrames.emplace(boneName, std::vector<BoneFrame>());
	}

	std::optional<std::reference_wrapper<const BoneFrame>> Animation::FindBoneFrame(const std::string &boneName, const std::size_t index) const
	{
		if (const auto boneFrames = FindBoneFrames(boneName))
			return std::make_optional(std::cref(boneFrames->get()[index]));
		return std::nullopt;
	}

	std::optional<std::reference_wrapper<const std::vector<BoneFrame>>> Animation::FindBoneFrames(const std::string &boneName) const
	{
		if (const auto pos = m_boneFrames.find(boneName); pos != m_boneFrames.cend())
			return std::make_optional(std::cref(pos->second));
		return std::nullopt;
	}

	bool Animation::GetHas(const std::string &boneName) const
	{
		return m_boneFrames.contains(boneName);
	}

	const std::unordered_map<std::string, std::vector<BoneFrame>> &Animation::GetBoneFrames() const
	{
		return m_boneFrames;
	}

	const std::string &Animation::GetName() const
	{
		return m_name;
	}

	void Animation::SetName(const std::string &name)
	{
		m_name = name;
	}

	// void Animation::SetBoneFrames(const std::string boneName, const std::vector<BoneFrame> &frames)
	// {
	// 	if (m_boneFrames.contains(boneName))
	// 		m_boneFrames.at(boneName) = frames;
	// 	else
	// 		Log::Get().Print<LogMode::Error>("BoneFrames atanamadi. BoneName mevcut degil.");
	// }
}

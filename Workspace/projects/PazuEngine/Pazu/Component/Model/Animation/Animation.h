#pragma once
#include "BoneFrame.h"

namespace Pazu
{
	class Animation
	{
	public:
		Animation() = default;
		Animation(const std::string &name, const std::unordered_map<std::string, std::vector<BoneFrame>> &boneFrames);
		void AddBoneFrame(const std::string &boneName, const BoneFrame &boneFrame);
		void AddBoneFrames(const std::string &boneName, const std::vector<BoneFrame> &boneFrames = {});
		std::optional<std::reference_wrapper<const BoneFrame>> FindBoneFrame(const std::string &boneName, const std::size_t index) const;
		std::optional<std::reference_wrapper<const std::vector<BoneFrame>>> FindBoneFrames(const std::string &boneName) const;
		bool GetHas(const std::string &boneName) const;
		const std::unordered_map<std::string, std::vector<BoneFrame>> &GetBoneFrames() const;
		const std::string &GetName() const;
		void SetName(const std::string &name);
		// void SetBoneFrames(const std::string boneName, const std::vector<BoneFrame> &frames);

	private:
		std::string m_name;
		std::unordered_map<std::string, std::vector<BoneFrame>> m_boneFrames;
	};
}

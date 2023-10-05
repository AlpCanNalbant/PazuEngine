// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "Animation.h"

namespace Pazu
{
	class Animator
	{
	public:
		Animator() = default;
		Animator(std::initializer_list<Animation> animations);
		Animator(const std::vector<Animation> &animations);
		Animator(std::vector<Animation> &&animations);

		void Play(const bool replay = false);
		void Add(const Animator &animator);
		void Add(Animator &&animator);
		template <typename T>
			requires std::convertible_to<T, Animation>
		bool AddAnimation(T &&animation);
		std::optional<std::reference_wrapper<const Animation>> FindAnimation(const std::string &name) const;
		std::optional<std::reference_wrapper<Animation>> FindAnimation(const std::string &name);

		const Animation &GetCurrent() const;
		bool SetCurrent(const Animation &animation);
		bool SetCurrent(const std::string &name);

	private:
		std::vector<Animation> animations_;
		const Animation *currentAnimation_{nullptr};
	};
}

#include "Animator.inl"

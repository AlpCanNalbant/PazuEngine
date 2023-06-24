#include "Animator.h"

namespace Pazu
{
	Animator::Animator(std::initializer_list<Animation> animations)
			: animations_(animations), currentAnimation_(&animations_.front()) {}

	Animator::Animator(const std::vector<Animation> &animations)
			: animations_(animations), currentAnimation_(&animations_.front()) {}

	Animator::Animator(std::vector<Animation> &&animations)
			: animations_(std::move(animations)), currentAnimation_(&animations_.front()) {}

	void Animator::Play(const bool replay)
	{
	}

	void Animator::Add(const Animator &animator)
	{
	}

	void Animator::Add(Animator &&animator)
	{
	}

	std::optional<std::reference_wrapper<const Animation>> Animator::FindAnimation(const std::string &name) const
	{
		if (const auto pos = std::find_if(animations_.cbegin(), animations_.cend(), [&name](const auto &a)
																			{ return a.GetName() == name; });
				pos != animations_.cend())
		{
			return std::make_optional(std::cref(*pos));
		}

		return std::nullopt;
	}

	std::optional<std::reference_wrapper<Animation>> Animator::FindAnimation(const std::string &name)
	{
		if (auto pos = std::find_if(animations_.begin(), animations_.end(), [&name](const auto &a)
																{ return a.GetName() == name; });
				pos != animations_.cend())
		{
			return std::make_optional(std::ref(*pos));
		}

		return std::nullopt;
	}

	const Animation &Animator::GetCurrent() const
	{
		return *currentAnimation_;
	}

	bool Animator::SetCurrent(const Animation &animation)
	{
		if (FindAnimation(animation.GetName()))
		{
			currentAnimation_ = &animation;

			return true;
		}

		return false;
	}

	bool Animator::SetCurrent(const std::string &name)
	{
		if (const auto animation = FindAnimation(name))
		{
			currentAnimation_ = &animation.value().get();

			return true;
		}

		return false;
	}
}

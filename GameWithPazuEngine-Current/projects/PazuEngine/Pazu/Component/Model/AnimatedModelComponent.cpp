#include "AnimatedModelComponent.h"

namespace Pazu
{
	AnimatedModelComponent::AnimatedModelComponent(const std::shared_ptr<AnimatedModelAsset> &asset)
	{
		SetAsset(asset);
	}

	const Animator &AnimatedModelComponent::GetAnimator() const
	{
		return m_animator;
	}

	Animator &AnimatedModelComponent::GetAnimator()
	{
		return m_animator;
	}

	const Skeleton &AnimatedModelComponent::GetSkeleton() const
	{
		return m_skeleton;
	}

	Skeleton &AnimatedModelComponent::GetSkeleton()
	{
		return m_skeleton;
	}

	void AnimatedModelComponent::SetAsset(const std::shared_ptr<AnimatedModelAsset> &asset)
	{
		ModelComponent::SetAsset(asset);
		m_animator = asset->animator;
		m_skeleton = asset->skeleton;
	}
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Asset/AnimatedModelAsset.h"
#include "Animation/Animator.h"
#include "Animation/Skeleton.h"
#include "Surface/SurfaceAnimatedModel.h"
#include "ModelComponent.h"

namespace Pazu
{
	class AnimatedModelComponent : public ModelComponent<SurfaceAnimatedModel>
	{
	public:
		AnimatedModelComponent() = default;
		AnimatedModelComponent(const std::shared_ptr<AnimatedModelAsset> &asset);
		const Animator &GetAnimator() const;
		Animator &GetAnimator();
		const Skeleton &GetSkeleton() const;
		Skeleton &GetSkeleton();
		void SetAsset(const std::shared_ptr<AnimatedModelAsset> &asset) final;

	private:
		Animator m_animator;
		Skeleton m_skeleton;
	};
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../Component/Model/Animation/Skeleton.h"
#include "../Component/Model/Animation/Animator.h"
#include "../Component/Model/Surface/SurfaceStaticModel.h"
#include "../Component/Model/Surface/SurfaceAnimatedModel.h"
#include "IAsset.h"

namespace Pazu
{
	template <typename T>
	struct ModelAsset;

	template <>
	struct ModelAsset<SurfaceStaticModel> : public IAsset
	{
		ModelAsset() = default;

		ModelAsset(std::vector<SurfaceStaticModel> &&surfaces)
			: surfaces(std::move(surfaces)) {}

		std::vector<SurfaceStaticModel> surfaces;
	};

	template <>
	struct ModelAsset<SurfaceAnimatedModel> : public IAsset
	{
		ModelAsset() = default;

		ModelAsset(std::vector<SurfaceAnimatedModel> &&surfaces, Animator &&animator, Skeleton &&skeleton)
			: surfaces(std::move(surfaces)), animator(std::move(animator)), skeleton(std::move(skeleton)) {}

		std::vector<SurfaceAnimatedModel> surfaces;
		Animator animator;
		Skeleton skeleton;
	};
}

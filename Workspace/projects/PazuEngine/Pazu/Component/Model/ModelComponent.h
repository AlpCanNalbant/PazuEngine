// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../IComponent.h"

namespace Pazu
{
	template <typename T>
	struct ModelAsset;
	template <typename T>
	class ModelComponent : public IComponent
	{
	public:
		ModelComponent() = default;
		ModelComponent(const std::shared_ptr<ModelAsset<T>> &asset);
		void AddSurface();
		std::optional<std::reference_wrapper<const std::unique_ptr<T>>> FindSurface(const std::shared_ptr<Material> &material) const;
		const std::vector<std::unique_ptr<T>> &GetSurfaces() const;
		virtual void SetAsset(const std::shared_ptr<ModelAsset<T>> &asset);

	protected:
		std::vector<std::unique_ptr<T>> m_surfaces;
		std::shared_ptr<ModelAsset<T>> m_asset;
	};
}
#include "ModelComponent.inl"

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "Loader/IAssetLoader.h"

namespace Pazu::Graphics
{
	class Device;
}
namespace Pazu
{
	struct IAsset;
	class AssetManager
	{
	public:
		AssetManager();
		AssetManager(const std::shared_ptr<Graphics::Device> &graphicsDevice);
		template <typename T>
		std::shared_ptr<T> Load(const std::string &path) const;
		const std::shared_ptr<Graphics::Device> &GetGraphicsDevice() const;
		void SetGraphicsDevice(const std::shared_ptr<Graphics::Device> &graphicsDevice);

	private:
		std::shared_ptr<Graphics::Device> m_graphicsDevice;
		mutable std::unordered_map<std::string, std::weak_ptr<IAsset>> m_cache;
		const std::unordered_map<std::type_index, std::shared_ptr<IAssetLoader>> m_loaders;
	};
} // namespace Pazu
#include "AssetManager.inl"

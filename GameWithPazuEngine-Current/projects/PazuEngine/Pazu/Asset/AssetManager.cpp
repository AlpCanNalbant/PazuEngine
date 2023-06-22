#include "StaticModelAsset.h"
#include "AnimatedModelAsset.h"
#include "ShaderAsset.h"
#include "TextureAsset.h"
#include "Loader/StaticModelAssetLoader.h"
#include "Loader/AnimatedModelAssetLoader.h"
#include "Loader/ShaderAssetLoader.h"
#include "Loader/TextureAssetLoader.h"
#include "AssetManager.h"

namespace Pazu
{
	AssetManager::AssetManager()
			: AssetManager(nullptr) {}

	AssetManager::AssetManager(const std::shared_ptr<Graphics::Device> &graphicsDevice)
			: m_graphicsDevice(graphicsDevice),
				m_loaders({{typeid(StaticModelAsset), std::make_shared<StaticModelAssetLoader>()},
									 {typeid(AnimatedModelAsset), std::make_shared<AnimatedModelAssetLoader>()},
									 {typeid(ShaderAsset), std::make_shared<ShaderAssetLoader>()},
									 {typeid(TextureAsset), std::make_shared<TextureAssetLoader>()}}) {}

	const std::shared_ptr<Graphics::Device> &AssetManager::GetGraphicsDevice() const
	{
		return m_graphicsDevice;
	}

	void AssetManager::SetGraphicsDevice(const std::shared_ptr<Graphics::Device> &graphicsDevice)
	{
		m_graphicsDevice = graphicsDevice;
	}
} // namespace Pazu

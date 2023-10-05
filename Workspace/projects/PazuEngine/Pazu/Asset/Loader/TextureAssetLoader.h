// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "IAssetLoader.h"

class ResourceHandle;
namespace Pazu::Graphics::Direct3D11
{
	struct TextureData;
}
namespace Pazu
{
	class TextureAssetLoader : public IAssetLoader
	{
	public:
		std::shared_ptr<IAsset> Load(const std::string &file, const AssetManager &assetMgr) const final;

	private:
		std::shared_ptr<IAsset> LoadTexture(const ResourceHandle &resourceHandle, const AssetManager &assetMgr) const;
		void LoadTextureData(const ResourceHandle &resourceHandle, const std::shared_ptr<Graphics::Direct3D11::TextureData> &data) const;
		// void LoadTextureData(const ResourceHandle &resourceHandle, const std::shared_ptr<OpenGL::TextureData> &data) const ;
	};
} // namespace Pazu

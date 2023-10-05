// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "IAssetLoader.h"

namespace Pazu
{
	class ShaderAssetLoader : public IAssetLoader
	{
	public:
		std::shared_ptr<IAsset> Load(const std::string &file, const AssetManager &assetMgr) const final;

	private:
		std::shared_ptr<IAsset> LoadShader(const std::string &fileSource, const std::string &basePath, const AssetManager &assetMgr) const;
		std::string GetCompiledSource(const std::string &file) const;
	};
} // namespace Pazu

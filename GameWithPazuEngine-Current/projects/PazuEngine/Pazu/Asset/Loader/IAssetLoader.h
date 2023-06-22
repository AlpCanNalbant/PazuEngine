#pragma once

namespace Pazu
{
	class AssetManager;
	struct IAsset;
	class IAssetLoader
	{
	public:
		virtual ~IAssetLoader() = default;
		virtual std::shared_ptr<IAsset> Load(const std::string &file, const AssetManager &assetMgr) const = 0;
	};
} // namespace Pazu

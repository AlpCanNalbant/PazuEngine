#include <algorithm>
#include <ResourceManager/ResourceHandle.h>
#if defined(_WIN32)
#include <DDSTextureLoader/DDSTextureLoader11.h>
#elif
#include <SOIL2/SOIL2.h>
#endif
#include "../AssetManager.h"
#include "../../Graphics/Device.h"
#include "../../Graphics/Texture/Texture2D.h"
#include "../../Graphics/Handle/Direct3D11/Texture/TextureData.h"
#include "../TextureAsset.h"
#include "TextureAssetLoader.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	std::shared_ptr<IAsset> TextureAssetLoader::Load(const std::string &file, const AssetManager &assetMgr) const
	{
		std::string fileFormat(file.cend() - 3, file.cend());
		std::transform(fileFormat.cbegin(), fileFormat.cend(), fileFormat.begin(), [](auto c)
									 { return std::tolower(c); });
		if (fileFormat != "dds")
			return Log::Get().Print<LogMode::Error, std::nullptr_t>("Texture yuklenemedi. Dosya formati desteklenmiyor.");
		const ResourceHandle rh(file);
		if (!rh.isValid())
			return Log::Get().Print<LogMode::Error, std::nullptr_t>("Texture dosyasi " + file + " bulunamadi.");
		if (const auto texture = LoadTexture(rh, assetMgr))
			return texture;
		return Log::Get().Print<LogMode::Error, std::nullptr_t>("Texture dosyasi " + file + " yuklenemedi.");
	}

	std::shared_ptr<IAsset> TextureAssetLoader::LoadTexture(const ResourceHandle &resourceHandle, const AssetManager &assetMgr) const
	{
		switch (Engine::GetGraphicsApi())
		{
		case Api::Direct3D11:
		{
			const auto data = std::make_shared<Direct3D11::TextureData>();
			LoadTextureData(resourceHandle, data);
			Texture2D texture2d(data, {data->ddsHeader->width, data->ddsHeader->height});
			assetMgr.GetGraphicsDevice()->CreateTexture(texture2d);
			return std::make_shared<TextureAsset>(std::move(texture2d));
		}
		case Api::OpenGL:
			return nullptr;
		default:
			return nullptr;
		}
	}

	void TextureAssetLoader::LoadTextureData(const ResourceHandle &resourceHandle, const std::shared_ptr<Direct3D11::TextureData> &data) const
	{
		if (HRESULT hResult; FAILED(hResult = DirectX::DDSTextureData::LoadTextureDataFromMemory(resourceHandle.data(), resourceHandle.size(), &data->ddsHeader, &data->bitData, &data->bitSize)))
			WLog::Get().Print<LogMode::Error>(L"Texture verisi alinamadi. " + Log::Get().ToString(hResult));
	}

	// void TextureAssetLoader::LoadTextureData(const ResourceHandle &resourceHandle, const std::shared_ptr<OpenGL::TextureData> &data) const
	// {
	// 	int width, height, channels;
	// 	const auto data = std::shared_ptr<unsigned char>(SOIL_load_image_from_memory(resourceHandle.data(), resourceHandle.size(), &width, &height, &channels, SOIL_LOAD_AUTO));
	// 	if (!data)
	// 		return Log::Get().Print<LogMode::Error>({"Texture verisi alinamadi. SOIL hata mesaji: ", SOIL_last_result()});
	// }
} // namespace Pazu

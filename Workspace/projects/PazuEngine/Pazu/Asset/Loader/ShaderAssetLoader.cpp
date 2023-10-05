// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include <algorithm>
#include <ResourceManager/ResourceHandle.h>
#include "../AssetManager.h"
#include "../../Graphics/Device.h"
#include "../../Graphics/Shader/VertexShader.h"
#include "../../Graphics/Shader/PixelShader.h"
#include "../ShaderAsset.h"
#include "ShaderAssetLoader.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	std::shared_ptr<IAsset> ShaderAssetLoader::Load(const std::string &file, const AssetManager &assetMgr) const
	{
		const ResourceHandle rh(file);
		if (!rh.isValid())
			return Log::Get().Print<LogMode::Error, std::nullptr_t>("Shader dosyasi " + file + " bulunamadi.");
		if (const auto shader = LoadShader(rh.string(), PathStep(file).Backward().GetSource(), assetMgr))
			return shader;
		return Log::Get().Print<LogMode::Error, std::nullptr_t>("Shader dosyasi " + file + " yuklenemedi.");
	}

	std::shared_ptr<IAsset> ShaderAssetLoader::LoadShader(const std::string &fileSource, const std::string &basePath, const AssetManager &assetMgr) const
	{
		std::array<std::string, 2> sources;
		std::string realFile;
		std::string typeTitle;
		int currentType = -1;
		for (auto first = fileSource.begin(), last = fileSource.cend(); first != last; ++first)
		{
			if (*first == '@')
			{
				++first;
				currentType = -1;
				for (std::size_t x = 0; currentType == -1 && first != last; ++x, ++first)
				{
					typeTitle += *first;
					std::transform(typeTitle.begin() + x, typeTitle.end(), typeTitle.begin() + x, [](auto c)
								   { return std::tolower(c); });
					if (typeTitle == "vertex")
						currentType = 0;
					else if (typeTitle == "pixel")
						currentType = 1;
					else if (typeTitle == "global")
						currentType = 2;
					else if (typeTitle == "direct3d")
						currentType = 3;
					else if (typeTitle == "opengl")
						currentType = 4;
				}
				typeTitle.clear();
			}
			if (*first == '\n' || *first == '\r')
				continue;
			switch (currentType)
			{
			case 0:
			case 1:
				sources[currentType] += *first;
				break;
			case 2:
				for (auto &code : sources)
					code += *first;
				break;
			case 3:
				if (Engine::GetGraphicsApi() == Api::Direct3D11)
					realFile += *first;
				break;
			case 4:
				if (Engine::GetGraphicsApi() == Api::OpenGL)
					realFile += *first;
				break;
			default:
				break;
			}
		}
		if ((sources[0].empty() || sources[1].empty()) && realFile.empty())
			return Log::Get().Print<LogMode::Error, std::nullptr_t>("Shader veri icerigi bos.");
		if (!realFile.empty())
			return Load(realFile, assetMgr);
		std::array<bool, sources.size()> compileds = {};
		for (std::size_t x = 0; x < sources.size(); ++x)
		{
			if (sources[x].find("main") == std::string::npos)
			{
				sources[x] = GetCompiledSource(basePath + sources[x]);
				compileds[x] = true;
			}
		}
		const auto shaderAsset = std::make_shared<ShaderAsset>();
		auto vertexShader = std::make_unique<VertexShader>(sources[0], compileds[0]);
		auto pixelShader = std::make_unique<PixelShader>(sources[1], compileds[1]);
		assetMgr.GetGraphicsDevice()->CreateShader(*vertexShader);
		assetMgr.GetGraphicsDevice()->CreateShader(*pixelShader);
		shaderAsset->stages[typeid(VertexShader)] = std::move(vertexShader);
		shaderAsset->stages[typeid(PixelShader)] = std::move(pixelShader);
		return shaderAsset;
	}

	std::string ShaderAssetLoader::GetCompiledSource(const std::string &file) const
	{
		if (const ResourceHandle rh(file); rh.isValid())
			return rh.string();
		return Log::Get().Print<LogMode::Error, std::string>(file + " derlenmis shader kaynak dosyasi bulunamadi.");
	}
} // namespace Pazu

#pragma once
#include <DDSTextureLoader/DDSTextureLoader11.h>
#include "../../../Texture/ITextureData.h"

namespace Pazu::Graphics::Direct3D11
{
	struct TextureData : public ITextureData
	{
		TextureData() = default;
		TextureData(DDS_HEADER *ddsHeader, uint8_t *bitData, std::size_t bitSize);

		const DDS_HEADER *ddsHeader{nullptr};
		const uint8_t *bitData{nullptr};
		std::size_t bitSize{0};
	};
}

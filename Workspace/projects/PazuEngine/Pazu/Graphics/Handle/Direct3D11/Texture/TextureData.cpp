// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "TextureData.h"

namespace Pazu::Graphics::Direct3D11
{
	TextureData::TextureData(DDS_HEADER *ddsHeader, uint8_t *bitData, std::size_t bitSize)
		: ddsHeader(ddsHeader), bitData(bitData), bitSize(bitSize) {}
}

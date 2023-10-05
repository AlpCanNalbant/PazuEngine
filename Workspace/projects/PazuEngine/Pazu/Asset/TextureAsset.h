// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../Graphics/Texture/Texture2D.h"
#include "IAsset.h"

namespace Pazu
{
	struct TextureAsset : public IAsset
	{
		TextureAsset() = default;
		TextureAsset(Graphics::Texture2D texture2d);

		Graphics::Texture2D texture2d;
	};
}

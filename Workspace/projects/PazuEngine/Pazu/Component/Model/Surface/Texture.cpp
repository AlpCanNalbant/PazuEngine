// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../../../Asset/TextureAsset.h"
#include "Texture.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	Texture::Texture(const std::shared_ptr<TextureAsset> &asset)
		: m_asset(asset) {}

	const Size &Texture::GetSize() const
	{
		return m_asset->texture2d.GetSize();
	}

	const Graphics::Texture2D &Texture::Get() const
	{
		return m_asset->texture2d;
	}

	void Texture::SetAsset(const std::shared_ptr<TextureAsset> &asset)
	{
		m_asset = asset;
	}
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	class Texture2D;
}
namespace Pazu
{
	struct TextureAsset;
	class Texture
	{
	public:
		Texture() = default;
		Texture(const std::shared_ptr<TextureAsset> &asset);
		const Size &GetSize() const;
		const Graphics::Texture2D &Get() const;
		void SetAsset(const std::shared_ptr<TextureAsset> &asset);

	private:
		std::shared_ptr<TextureAsset> m_asset;
	};
}

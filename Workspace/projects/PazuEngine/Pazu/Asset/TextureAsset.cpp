#include "TextureAsset.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	TextureAsset::TextureAsset(Graphics::Texture2D texture2d)
			: texture2d(std::move(texture2d)) {}
}

#pragma once
#include "TextureHandle.h"
#include "../../../Texture/Texture2D.h"

namespace Pazu::Graphics::Direct3D11
{
	class Texture2DHandle : public TextureHandle
	{
	public:
		using TextureHandle::TextureHandle;
	};
}

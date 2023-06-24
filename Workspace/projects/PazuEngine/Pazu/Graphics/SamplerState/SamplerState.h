#pragma once
#include "../Object.h"
#include "TextureFilter.h"
#include "TextureWrap.h"

namespace Pazu::Graphics
{
	class SamplerState : public Object
	{
	public:
		SamplerState()  = default;
		SamplerState(const TextureFilter textureFilter, const TextureWrap textureWrap = TextureWrap::Repeat, const bool mipmap = true) ;
		TextureFilter GetTextureFilter() const ;
		TextureWrap GetTextureWrap() const ;
		bool GetMipmap() const ;
		void SetTextureFilter(const TextureFilter textureFilter) ;
		void SetTextureWrap(const TextureWrap textureWrap) ;
		void SetMipmap(const bool mipmap) ;

	private:
		TextureFilter m_textureFilter;
		TextureWrap m_textureWrap;
		bool m_mipmap;
	};
}

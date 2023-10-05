// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "SamplerState.h"

namespace Pazu::Graphics
{
	SamplerState::SamplerState(const TextureFilter textureFilter, const TextureWrap textureWrap, const bool mipmap)
		: m_textureFilter(textureFilter), m_textureWrap(textureWrap), m_mipmap(mipmap) {}

	TextureFilter SamplerState::GetTextureFilter() const
	{
		return m_textureFilter;
	}

	TextureWrap SamplerState::GetTextureWrap() const
	{
		return m_textureWrap;
	}

	bool SamplerState::GetMipmap() const
	{
		return m_mipmap;
	}

	void SamplerState::SetTextureFilter(const TextureFilter textureFilter)
	{
		m_textureFilter = textureFilter;
	}

	void SamplerState::SetTextureWrap(const TextureWrap textureWrap)
	{
		m_textureWrap = textureWrap;
	}

	void SamplerState::SetMipmap(const bool mipmap)
	{
		m_mipmap = mipmap;
	}
}

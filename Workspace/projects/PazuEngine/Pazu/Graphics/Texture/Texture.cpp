// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Texture.h"

namespace Pazu::Graphics
{
	Texture::Texture(const std::shared_ptr<ITextureData> &data, const Size &size)
		: m_data(data), m_size(size) {}

	const Size &Texture::GetSize() const
	{
		return m_size;
	}

	void Texture::SetData(const std::shared_ptr<ITextureData> &data)
	{
		m_data = data;
	}

	void Texture::SetSize(const Size &size)
	{
		m_size = size;
	}
}

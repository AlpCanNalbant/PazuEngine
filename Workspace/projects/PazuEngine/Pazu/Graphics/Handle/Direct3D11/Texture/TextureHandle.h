// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TextureData.h"
#include "../../../Texture/Texture.h"
#include "../../../IObjectHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class TextureHandle : public IObjectHandle
	{
	public:
		TextureHandle(const Texture &texture);
		const UniqueComPtr<ID3D11ShaderResourceView> &GetShaderResourceView() const;
		const std::shared_ptr<TextureData> &GetData() const;
		void SetShaderResourceView(UniqueComPtr<ID3D11ShaderResourceView> shaderResourceView);

	protected:
		UniqueComPtr<ID3D11ShaderResourceView> m_resourceView;
		std::shared_ptr<TextureData> m_data;
	};
}

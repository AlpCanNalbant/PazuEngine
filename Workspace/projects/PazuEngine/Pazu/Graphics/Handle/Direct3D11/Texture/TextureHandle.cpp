#include "../../../../Math/Color.h"
#include "Texture2DHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	TextureHandle::TextureHandle(const Texture &texture)
			: m_data(texture.GetData<TextureData>()) {}

	const UniqueComPtr<ID3D11ShaderResourceView> &TextureHandle::GetShaderResourceView() const
	{
		return m_resourceView;
	}

	const std::shared_ptr<TextureData> &TextureHandle::GetData() const
	{
		return m_data;
	}

	void TextureHandle::SetShaderResourceView(UniqueComPtr<ID3D11ShaderResourceView> shaderResouceView)
	{
		m_resourceView = std::move(shaderResouceView);
	}
}

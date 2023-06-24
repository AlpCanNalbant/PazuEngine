#include "PixelShaderHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	PixelShaderHandle::PixelShaderHandle(PixelShader &pixelShader)
			: ShaderHandle(pixelShader, "ps_5_0") {}

	const UniqueComPtr<ID3D11PixelShader> &PixelShaderHandle::Get() const
	{
		return m_shader;
	}

	void PixelShaderHandle::Set(UniqueComPtr<ID3D11PixelShader> shader)
	{
		m_shader = std::move(shader);
	}
}

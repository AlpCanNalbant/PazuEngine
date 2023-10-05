// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Shader/PixelShader.h"
#include "ShaderHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class PixelShaderHandle : public ShaderHandle
	{
	public:
		PixelShaderHandle(PixelShader &pixelShader);
		const UniqueComPtr<ID3D11PixelShader> &Get() const;
		void Set(UniqueComPtr<ID3D11PixelShader> shader);

	private:
		UniqueComPtr<ID3D11PixelShader> m_shader;
	};
}

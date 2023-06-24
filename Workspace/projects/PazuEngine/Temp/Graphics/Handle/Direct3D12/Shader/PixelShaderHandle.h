#pragma once
#include "../../../Shader/PixelShader.h"
#include "ShaderHandle.h"

namespace Pazu::Direct3D12
{
	class PixelShaderHandle : public ShaderHandle
	{
	public:
		PixelShaderHandle(ID3D12Device &device, PixelShader &pixelShader) noexcept;
	};
}

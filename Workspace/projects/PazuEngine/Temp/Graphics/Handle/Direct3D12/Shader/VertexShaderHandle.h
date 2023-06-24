#pragma once
#include "../../../Shader/VertexShader.h"
#include "ShaderHandle.h"

namespace Pazu::Direct3D12
{
	class VertexShaderHandle : public ShaderHandle
	{
	public:
		VertexShaderHandle(ID3D12Device &device, VertexShader &vertexShader) noexcept;
	};
} // namespace Pazu::Direct3D12

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "VertexShaderHandle.h"
using namespace Microsoft::WRL;

namespace Pazu::Direct3D12
{
	VertexShaderHandle::VertexShaderHandle(ID3D12Device &device, VertexShader &vertexShader) noexcept
		: ShaderHandle(device, vertexShader, "vs_5_0") {}
}

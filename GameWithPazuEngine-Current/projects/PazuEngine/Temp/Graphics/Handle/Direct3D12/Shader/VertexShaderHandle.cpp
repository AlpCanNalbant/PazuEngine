#include "VertexShaderHandle.h"
using namespace Microsoft::WRL;

namespace Pazu::Direct3D12
{
	VertexShaderHandle::VertexShaderHandle(ID3D12Device &device, VertexShader &vertexShader) noexcept
			: ShaderHandle(device, vertexShader, "vs_5_0") {}
}

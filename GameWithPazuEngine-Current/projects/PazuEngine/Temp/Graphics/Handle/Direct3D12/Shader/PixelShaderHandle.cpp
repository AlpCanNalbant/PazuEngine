#include "PixelShaderHandle.h"
using namespace Microsoft::WRL;

namespace Pazu::Direct3D12
{
	PixelShaderHandle::PixelShaderHandle(ID3D12Device &device, PixelShader &pixelShader) noexcept
			: ShaderHandle(device, pixelShader, "ps_5_0") {}
}

#include "ConstantBufferHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	ConstantBufferHandle::ConstantBufferHandle(const ConstantBuffer &constantBuffer)
			: BufferHandle(constantBuffer, D3D11_BIND_CONSTANT_BUFFER, constantBuffer.GetByteSize()) {}
}

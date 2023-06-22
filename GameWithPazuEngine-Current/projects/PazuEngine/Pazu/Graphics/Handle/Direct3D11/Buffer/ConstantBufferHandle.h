#pragma once
#include "../../../Buffer/ConstantBuffer.h"
#include "BufferHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class ConstantBufferHandle : public BufferHandle
	{
	public:
		ConstantBufferHandle(const ConstantBuffer &constantBuffer);
	};
}

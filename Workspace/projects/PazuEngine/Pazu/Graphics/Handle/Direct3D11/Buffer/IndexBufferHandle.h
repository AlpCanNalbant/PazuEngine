// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Buffer/IndexBuffer.h"
#include "BufferHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class IndexBufferHandle : public BufferHandle
	{
	public:
		template <typename T>
		IndexBufferHandle(const IndexBuffer<T> &indexBuffer);
	};
}
#include "IndexBufferHandle.inl"

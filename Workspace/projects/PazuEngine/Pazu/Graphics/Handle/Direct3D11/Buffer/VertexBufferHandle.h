#pragma once
#include "../../../Buffer/VertexBuffer.h"
#include "BufferHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class VertexBufferHandle : public BufferHandle
	{
	public:
		template <typename T>
		VertexBufferHandle(const VertexBuffer<T> &vertexBuffer);
	};
}
#include "VertexBufferHandle.inl"

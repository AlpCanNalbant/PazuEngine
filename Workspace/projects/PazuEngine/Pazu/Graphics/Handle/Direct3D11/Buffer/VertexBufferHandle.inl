// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics::Direct3D11
{
	template <typename T>
	VertexBufferHandle::VertexBufferHandle(const VertexBuffer<T> &vertexBuffer)
		: BufferHandle(vertexBuffer, D3D11_BIND_VERTEX_BUFFER, vertexBuffer.GetByteWidth()) {}
}

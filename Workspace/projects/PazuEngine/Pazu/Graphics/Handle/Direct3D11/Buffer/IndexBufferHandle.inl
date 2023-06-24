namespace Pazu::Graphics::Direct3D11
{
	template <typename T>
	IndexBufferHandle::IndexBufferHandle(const IndexBuffer<T> &indexBuffer)
			: BufferHandle(indexBuffer, D3D11_BIND_INDEX_BUFFER, indexBuffer.GetByteWidth()) {}
}

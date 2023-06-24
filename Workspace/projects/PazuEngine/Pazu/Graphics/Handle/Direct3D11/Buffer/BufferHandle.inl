namespace Pazu::Graphics::Direct3D11
{
	template <typename T>
	BufferHandle::BufferHandle(const Buffer<T> &buffer, const D3D11_BIND_FLAG bindFlag, const unsigned int byteSize)
	{
		m_desc.Usage = buffer.GetUsage() == BufferUsage::Static ? D3D11_USAGE_DEFAULT : D3D11_USAGE_DYNAMIC;
		m_desc.BindFlags = bindFlag;
		m_desc.ByteWidth = byteSize;
		m_data.pSysMem = buffer.GetData();
	}
}

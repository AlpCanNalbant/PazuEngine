// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "BufferHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	const UniqueComPtr<ID3D11Buffer> &BufferHandle::Get() const
	{
		return m_buffer;
	}

	const D3D11_BUFFER_DESC &BufferHandle::GetDesc() const
	{
		return m_desc;
	}

	const D3D11_SUBRESOURCE_DATA &BufferHandle::GetData() const
	{
		return m_data;
	}

	void BufferHandle::Set(UniqueComPtr<ID3D11Buffer> buffer)
	{
		m_buffer = std::move(buffer);
	}
}

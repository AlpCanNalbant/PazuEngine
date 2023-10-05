// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Buffer/Buffer.h"
#include "../../../IObjectHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class BufferHandle : public IObjectHandle
	{
	public:
		template <typename T>
		BufferHandle(const Buffer<T> &buffer, const D3D11_BIND_FLAG bindFlags, const unsigned int byteSize);
		const UniqueComPtr<ID3D11Buffer> &Get() const;
		const D3D11_BUFFER_DESC &GetDesc() const;
		const D3D11_SUBRESOURCE_DATA &GetData() const;
		void Set(UniqueComPtr<ID3D11Buffer> buffer);

	protected:
		UniqueComPtr<ID3D11Buffer> m_buffer;
		D3D11_BUFFER_DESC m_desc{};
		D3D11_SUBRESOURCE_DATA m_data{};
	};
}
#include "BufferHandle.inl"

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	template <typename T>
	void ConstantBuffer::Set(const T &object)
	{
		Buffer<const void *>::m_data[0] = &object;
		m_byteSize += sizeof(T);
	}
}

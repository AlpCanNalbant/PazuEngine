// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "ConstantBuffer.h"

namespace Pazu::Graphics
{
	ConstantBuffer::ConstantBuffer(const ShaderFlag shaderFlags, const unsigned int slotIndex, const BufferUsage usage)
		: Buffer(usage), m_shaderFlags(shaderFlags), m_slotIndex(slotIndex)
	{
		m_data.reserve(1);
		m_data.resize(1);
	}

	ShaderFlag ConstantBuffer::GetShaderFlags() const
	{
		return m_shaderFlags;
	}

	unsigned int ConstantBuffer::GetSlotIndex() const
	{
		return m_slotIndex;
	}

	unsigned int ConstantBuffer::GetByteSize() const
	{
		return m_byteSize;
	}

	void ConstantBuffer::SetShaderFlags(const ShaderFlag shaderFlags)
	{
		m_shaderFlags = shaderFlags;
	}

	void ConstantBuffer::SetSlotIndex(const unsigned int slotIndex)
	{
		m_slotIndex = slotIndex;
	}

	void ConstantBuffer::SetByteSize(const unsigned int byteSize)
	{
		m_byteSize = byteSize;
	}
}

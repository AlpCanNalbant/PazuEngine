// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../Shader/ShaderFlag.h"
#include "Buffer.h"

namespace Pazu::Graphics
{
	class ConstantBuffer : public Buffer<const void *>
	{
	public:
		using Buffer<const void *>::Buffer;
		ConstantBuffer(const ShaderFlag shaderFlags, const unsigned int slotIndex, const BufferUsage usage);
		ShaderFlag GetShaderFlags() const;
		unsigned int GetSlotIndex() const;
		unsigned int GetByteSize() const;
		template <typename T>
		void Set(const T &object);
		void SetShaderFlags(const ShaderFlag shaderFlags);
		void SetSlotIndex(const unsigned int slotIndex);
		void SetByteSize(const unsigned int byteSize);

	private:
		ShaderFlag m_shaderFlags;
		unsigned int m_byteSize{0};
		unsigned int m_slotIndex{0};
	};
}
#include "ConstantBuffer.inl"

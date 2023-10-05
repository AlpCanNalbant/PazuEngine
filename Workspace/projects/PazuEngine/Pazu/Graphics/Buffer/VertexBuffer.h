// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "Buffer.h"

namespace Pazu::Graphics
{
	template <typename T>
	class VertexBuffer : public Buffer<T>
	{
	public:
		using Buffer<T>::Buffer;
		void Add(const T &vertex);
		void Add(const VertexBuffer &other);
		const std::vector<T> &GetVertices() const;
		unsigned int GetByteWidth() const;
		unsigned int GetStride() const;

	private:
		unsigned int m_byteWidth{0};
		unsigned int m_stride{0};
	};
}
#include "VertexBuffer.inl"

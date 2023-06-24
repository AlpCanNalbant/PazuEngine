#pragma once
#include "Buffer.h"

namespace Pazu::Graphics
{
	template <typename T>
	class IndexBuffer : public Buffer<T>
	{
	public:
		using Buffer<T>::Buffer;
		void Add(const std::array<T, 3> &indices);
		void Add(const IndexBuffer &other);
		const std::vector<T> &GetIndices() const;
		unsigned int GetByteWidth() const;

	private:
		unsigned int m_byteWidth{0};
	};
}
#include "IndexBuffer.inl"

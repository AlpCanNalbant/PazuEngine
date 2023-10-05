// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	template <typename T>
	void VertexBuffer<T>::Add(const T &vertex)
	{
		if (!m_stride)
			m_stride = sizeof(T);
		Buffer<T>::m_data.emplace_back(vertex);
		m_byteWidth += m_stride;
	}

	template <typename T>
	void VertexBuffer<T>::Add(const VertexBuffer &other)
	{
		if (other.m_data.empty())
			return Log::Get().Print<LogMode::Error>("VertexBuffer verisi eklenemedi.");
		if (!m_stride)
			m_stride = sizeof(T);
		Buffer<T>::m_data.insert(Buffer<T>::m_data.cend(), other.m_data.cbegin(), other.m_data.cend());
		m_byteWidth += m_stride;
	}

	template <typename T>
	const std::vector<T> &VertexBuffer<T>::GetVertices() const
	{
		return Buffer<T>::m_data;
	}

	template <typename T>
	unsigned int VertexBuffer<T>::GetByteWidth() const
	{
		return m_byteWidth;
	}

	template <typename T>
	unsigned int VertexBuffer<T>::GetStride() const
	{
		return m_stride;
	}
}

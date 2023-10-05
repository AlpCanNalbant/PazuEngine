// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	template <typename T>
	void IndexBuffer<T>::Add(const std::array<T, 3> &indices)
	{
		Buffer<T>::m_data.insert(Buffer<T>::m_data.cend(), indices.cbegin(), indices.cend());
		m_byteWidth += indices.size() * sizeof(T);
	}

	template <typename T>
	void IndexBuffer<T>::Add(const IndexBuffer &other)
	{
		if (other.m_data.empty())
			return Log::Get().Print<LogMode::Error>("IndexBuffer verisi eklenemedi.");
		Buffer<T>::m_data.insert(Buffer<T>::m_data.cend(), other.m_data.cbegin(), other.m_data.cend());
		m_byteWidth += other.m_data.size() * sizeof(T);
	}

	template <typename T>
	const std::vector<T> &IndexBuffer<T>::GetIndices() const
	{
		return Buffer<T>::m_data;
	}

	template <typename T>
	unsigned int IndexBuffer<T>::GetByteWidth() const
	{
		return m_byteWidth;
	}
}

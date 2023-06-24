namespace Pazu::Graphics
{
	template <typename T>
	Buffer<T>::Buffer(const BufferUsage usage)
			: m_usage(usage) {}

	template <typename T>
	const void *Buffer<T>::GetData() const
	{
		if constexpr (std::is_pointer_v<T>)
			return *m_data.data();
		else
			return m_data.data();
	}

	template <typename T>
	unsigned int Buffer<T>::GetSize() const
	{
		return m_data.size();
	}

	template <typename T>
	BufferUsage Buffer<T>::GetUsage() const
	{
		return m_usage;
	}

	template <typename T>
	void Buffer<T>::SetUsage(const BufferUsage usage)
	{
		m_usage = usage;
	}
}

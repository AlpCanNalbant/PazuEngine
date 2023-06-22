namespace Pazu::Graphics
{
	template <typename T>
	std::shared_ptr<T> Context::GetHandle() const
	{
		if constexpr (!std::is_same_v<T, IContextHandle>)
			return m_handle;
		else
			return std::static_pointer_cast<T>(m_handle);
	}
}

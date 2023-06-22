namespace Pazu::Graphics
{
	template <typename T>
	std::shared_ptr<T> Device::GetHandle() const
	{
		if constexpr (!std::is_same_v<T, IDeviceHandle>)
			return std::static_pointer_cast<T>(m_handle);
		else
			return m_handle;
	}
}

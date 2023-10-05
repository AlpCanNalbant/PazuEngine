// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	constexpr ProtectedPtr<T>::ProtectedPtr(T *ptr) noexcept
		: m_ptr(ptr) {}

	template <typename T>
	T *ProtectedPtr<T>::operator->() const noexcept
	{
		// if (!m_ptr)
		// 	TLog::Get().Print<LogMode::Fatal>("ProtectedPtr gecerli degil.");
		return m_ptr;
	}

	template <typename T>
	const T &ProtectedPtr<T>::operator*() const noexcept
	{
		// if (!m_ptr)
		// 	TLog::Get().Print<LogMode::Fatal>("ProtectedPtr gecerli degil.");
		return *m_ptr;
	}

	template <typename T>
	ProtectedPtr<T>::operator bool() const noexcept
	{
		return m_ptr == nullptr ? false : true;
	}

	template <typename T>
	bool ProtectedPtr<T>::operator==(const ProtectedPtr<T> &other) const noexcept
	{
		return m_ptr == other.m_ptr;
	}

	template <typename T>
	bool ProtectedPtr<T>::operator!=(const ProtectedPtr<T> &other) const noexcept
	{
		return m_ptr != other.m_ptr;
	}
} // namespace Pazu

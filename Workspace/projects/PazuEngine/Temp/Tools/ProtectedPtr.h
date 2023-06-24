#pragma once

namespace Pazu
{
	template <typename T>
	class ProtectedPtr : public INonCopyable, public INonMovable
	{
	public:
		constexpr ProtectedPtr(T *ptr) noexcept;
		T *operator->() const noexcept;
		const T &operator*() const noexcept;
		explicit operator bool() const noexcept;
		bool operator==(const ProtectedPtr<T> &other) const noexcept;
		bool operator!=(const ProtectedPtr<T> &other) const noexcept;

	private:
		T *m_ptr;
	};
} // namespace Pazu
#include "ProtectedPtr.inl"

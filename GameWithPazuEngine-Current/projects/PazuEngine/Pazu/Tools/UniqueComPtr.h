#pragma once

namespace Pazu
{
	template <typename T>
	class UniqueComPtr
	{
	public:
		UniqueComPtr() = default;
		UniqueComPtr(const UniqueComPtr<T> &other) = delete;
		UniqueComPtr(UniqueComPtr<T> &&other);
		~UniqueComPtr();
		UniqueComPtr<T> &operator=(const UniqueComPtr<T> &other) = delete;
		UniqueComPtr<T> &operator=(UniqueComPtr<T> &&other);
		void Reset();
		T *operator->() const;
		operator T *() const;
		T *const *operator&() const;
		T **operator&();
		const T &operator*() const;
		T &operator*();
		explicit operator bool() const;

	private:
		T *m_comPtr{nullptr};
	};
}
#include "UniqueComPtr.inl"

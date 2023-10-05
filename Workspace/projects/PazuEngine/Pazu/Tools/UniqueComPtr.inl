// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "UniqueComPtr.h"

namespace Pazu
{
	template <typename T>
	UniqueComPtr<T>::UniqueComPtr(UniqueComPtr<T> &&other)
		: m_comPtr(other.m_comPtr)
	{
		other.m_comPtr = nullptr;
	}

	template <typename T>
	UniqueComPtr<T>::~UniqueComPtr()
	{
		Reset();
	}

	template <typename T>
	UniqueComPtr<T> &UniqueComPtr<T>::operator=(UniqueComPtr<T> &&other)
	{
		Reset();
		m_comPtr = other.m_comPtr;
		other.m_comPtr = nullptr;
		return *this;
	}

	template <typename T>
	void UniqueComPtr<T>::Reset()
	{
		if (m_comPtr)
		{
			m_comPtr->Release();
			m_comPtr = nullptr;
		}
	}

	template <typename T>
	T *UniqueComPtr<T>::operator->() const
	{
		// if (!m_ptr)
		// 	Log::Get().Print<LogMode::Fatal>("UniqueComPtr gecerli degil.");
		return m_comPtr;
	}

	template <typename T>
	UniqueComPtr<T>::operator T *() const
	{
		return m_comPtr;
	}

	template <typename T>
	T *const *UniqueComPtr<T>::operator&() const
	{
		return &m_comPtr;
	}

	template <typename T>
	T **UniqueComPtr<T>::operator&()
	{
		return &m_comPtr;
	}

	template <typename T>
	const T &UniqueComPtr<T>::operator*() const
	{
		// if (!m_ptr)
		// 	Log::Get().Print<LogMode::Fatal>("UniqueComPtr gecerli degil.");
		return *m_comPtr;
	}

	template <typename T>
	T &UniqueComPtr<T>::operator*()
	{
		// if (!m_ptr)
		// 	Log::Get().Print<LogMode::Fatal>("UniqueComPtr gecerli degil.");
		return *m_comPtr;
	}

	template <typename T>
	UniqueComPtr<T>::operator bool() const
	{
		return m_comPtr != nullptr;
	}
}

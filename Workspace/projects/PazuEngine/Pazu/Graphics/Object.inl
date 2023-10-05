// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	template <typename T>
	const T *Object::GetHandle() const
	{
		if constexpr (!std::is_same_v<T, IObjectHandle>)
			return static_cast<T *>(m_handle.get());
		else
			return m_handle.get();
	}

	template <typename T>
	void Object::SetHandle(std::unique_ptr<T> handle)
	{
		m_handle = std::move(handle);
	}
}

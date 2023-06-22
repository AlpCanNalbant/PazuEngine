#pragma once
#include "IObjectHandle.h"

namespace Pazu::Graphics
{
	class Object : public INonCopyable
	{
	public:
		template <typename T = IObjectHandle>
		const T *GetHandle() const;
		template <typename T>
		void SetHandle(std::unique_ptr<T> handle);

	protected:
		std::unique_ptr<IObjectHandle> m_handle;
	};
}
#include "Object.inl"

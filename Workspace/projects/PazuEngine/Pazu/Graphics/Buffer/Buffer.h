// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "BufferUsage.h"
#include "../Object.h"

namespace Pazu::Graphics
{
	template <typename T>
	class Buffer : public Object
	{
	public:
		Buffer() = default;
		Buffer(const BufferUsage usage);
		const void *GetData() const;
		unsigned int GetSize() const;
		BufferUsage GetUsage() const;
		void SetUsage(const BufferUsage usage);

	protected:
		std::vector<T> m_data;
		BufferUsage m_usage{BufferUsage::Static};
	};
}
#include "Buffer.inl"

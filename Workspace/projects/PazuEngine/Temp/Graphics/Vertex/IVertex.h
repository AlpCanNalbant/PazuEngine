// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "VertexFlag.h"

namespace Pazu
{
	template <typename T>
	class IVertex
	{
	public:
		virtual ~IVertex() noexcept = default;
		virtual std::vector<T> ToData() const noexcept = 0;
		virtual VertexFlag GetFlags() const noexcept = 0;
	};
}

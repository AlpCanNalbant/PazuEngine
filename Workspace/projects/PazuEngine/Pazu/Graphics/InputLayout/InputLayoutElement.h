// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	template <typename T>
	struct InputLayoutElement
	{
		InputLayoutElement() = default;
		constexpr InputLayoutElement(const T &input, const unsigned int byteOffset);

		T input;
		unsigned int byteOffset;
	};
}
#include "InputLayoutElement.inl"

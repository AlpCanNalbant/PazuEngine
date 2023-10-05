// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	template <typename T>
	constexpr InputLayoutElement<T>::InputLayoutElement(const T &input, const unsigned int byteOffset)
		: input(input), byteOffset(byteOffset) {}
}

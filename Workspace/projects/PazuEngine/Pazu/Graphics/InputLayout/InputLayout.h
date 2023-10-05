// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "InputLayoutElement.h"
#include "../Object.h"

namespace Pazu::Graphics
{
	template <typename T>
	class InputLayout : public Object
	{
	public:
		void Add(const InputLayoutElement<T> &element);
		const std::vector<InputLayoutElement<T>> &GetElements() const;

	protected:
		std::vector<InputLayoutElement<T>> m_elements;
	};
}
#include "InputLayout.inl"

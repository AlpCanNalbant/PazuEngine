// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	template <typename T>
	void InputLayout<T>::Add(const InputLayoutElement<T> &element)
	{
		m_elements.emplace_back(element);
	}

	template <typename T>
	const std::vector<InputLayoutElement<T>> &InputLayout<T>::GetElements() const
	{
		return m_elements;
	}
}

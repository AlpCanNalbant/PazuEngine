#include "InputLayoutHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	const UniqueComPtr<ID3D11InputLayout> &InputLayoutHandle::Get() const
	{
		return m_layout;
	}

	const std::vector<D3D11_INPUT_ELEMENT_DESC> &InputLayoutHandle::GetElements() const
	{
		return m_elements;
	}

	void InputLayoutHandle::Set(UniqueComPtr<ID3D11InputLayout> inputLayout)
	{
		m_layout = std::move(inputLayout);
	}
}

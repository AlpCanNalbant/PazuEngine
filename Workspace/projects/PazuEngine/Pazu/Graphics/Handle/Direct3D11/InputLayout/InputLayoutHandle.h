#pragma once
#include "../../../IObjectHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class InputLayoutHandle : public IObjectHandle
	{
	public:
		const UniqueComPtr<ID3D11InputLayout> &Get() const;
		const std::vector<D3D11_INPUT_ELEMENT_DESC> &GetElements() const;
		void Set(UniqueComPtr<ID3D11InputLayout> inputLayout);

	protected:
		UniqueComPtr<ID3D11InputLayout> m_layout;
		std::vector<D3D11_INPUT_ELEMENT_DESC> m_elements;
	};
}

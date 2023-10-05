// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../BlendState/BlendState.h"
#include "../../../IObjectHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class BlendStateHandle : public IObjectHandle
	{
	public:
		BlendStateHandle(const BlendState &blendState);
		const UniqueComPtr<ID3D11BlendState1> &Get() const;
		const D3D11_BLEND_DESC1 &GetDesc() const;
		void Set(UniqueComPtr<ID3D11BlendState1> blendState);

	private:
		UniqueComPtr<ID3D11BlendState1> m_blendState;
		D3D11_BLEND_DESC1 m_desc{};
	};
}

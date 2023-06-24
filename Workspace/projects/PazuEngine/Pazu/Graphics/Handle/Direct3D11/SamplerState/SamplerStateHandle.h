#pragma once
#include "../../../SamplerState/SamplerState.h"
#include "../../../IObjectHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class SamplerStateHandle : public IObjectHandle
	{
	public:
		SamplerStateHandle(const SamplerState &samplerState);
		const UniqueComPtr<ID3D11SamplerState> &Get() const;
		const D3D11_SAMPLER_DESC &GetDesc() const;
		void Set(UniqueComPtr<ID3D11SamplerState> samplerState);

	private:
		UniqueComPtr<ID3D11SamplerState> m_samplerState;
		D3D11_SAMPLER_DESC m_samplerDesc{};
	};
}

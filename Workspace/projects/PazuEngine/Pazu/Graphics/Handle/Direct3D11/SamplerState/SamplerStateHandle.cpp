// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "SamplerStateHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	SamplerStateHandle::SamplerStateHandle(const SamplerState &samplerState)
	{
		D3D11_FILTER filter;
		switch (samplerState.GetTextureFilter())
		{
		case TextureFilter::Nearest:
			filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
			break;
		case TextureFilter::Linear:
			filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
			break;
		case TextureFilter::Anisotropic:
			filter = D3D11_FILTER_ANISOTROPIC;
			break;
		default:
			break;
		}
		D3D11_TEXTURE_ADDRESS_MODE addressMode;
		switch (samplerState.GetTextureWrap())
		{
		case TextureWrap::Repeat:
			addressMode = D3D11_TEXTURE_ADDRESS_WRAP;
			break;
		case TextureWrap::Mirror:
			addressMode = D3D11_TEXTURE_ADDRESS_MIRROR;
			break;
		case TextureWrap::Clamp:
			addressMode = D3D11_TEXTURE_ADDRESS_CLAMP;
			break;
		default:
			break;
		}
		m_samplerDesc.Filter = filter;
		m_samplerDesc.AddressU = addressMode;
		m_samplerDesc.AddressV = addressMode;
		m_samplerDesc.AddressW = addressMode;
		m_samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		m_samplerDesc.MinLOD = 0;
		m_samplerDesc.MaxLOD = samplerState.GetMipmap() ? D3D11_FLOAT32_MAX : 0;
	}

	const UniqueComPtr<ID3D11SamplerState> &SamplerStateHandle::Get() const
	{
		return m_samplerState;
	}

	const D3D11_SAMPLER_DESC &SamplerStateHandle::GetDesc() const
	{
		return m_samplerDesc;
	}

	void SamplerStateHandle::Set(UniqueComPtr<ID3D11SamplerState> samplerState)
	{
		m_samplerState = std::move(samplerState);
	}
}

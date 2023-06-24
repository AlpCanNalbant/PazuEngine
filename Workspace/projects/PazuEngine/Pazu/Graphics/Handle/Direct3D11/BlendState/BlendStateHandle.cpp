#include "BlendStateHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	BlendStateHandle::BlendStateHandle(const BlendState &blendState)
	{
		D3D11_RENDER_TARGET_BLEND_DESC1 rtbDesc = {};
		rtbDesc.BlendEnable = blendState.GetEnable();
		rtbDesc.RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		rtbDesc.SrcBlend = D3D11_BLEND_SRC_COLOR;
		rtbDesc.DestBlend = D3D11_BLEND_BLEND_FACTOR;
		rtbDesc.BlendOp = D3D11_BLEND_OP_ADD;
		rtbDesc.SrcBlendAlpha = D3D11_BLEND_ONE;
		rtbDesc.DestBlendAlpha = D3D11_BLEND_ZERO;
		rtbDesc.BlendOpAlpha = D3D11_BLEND_OP_ADD;
		m_desc.RenderTarget[0] = rtbDesc;
		m_desc.AlphaToCoverageEnable = FALSE;
	}

	const UniqueComPtr<ID3D11BlendState1> &BlendStateHandle::Get() const
	{
		return m_blendState;
	}

	const D3D11_BLEND_DESC1 &BlendStateHandle::GetDesc() const
	{
		return m_desc;
	}

	void BlendStateHandle::Set(UniqueComPtr<ID3D11BlendState1> blendState)
	{
		m_blendState = std::move(blendState);
	}
}

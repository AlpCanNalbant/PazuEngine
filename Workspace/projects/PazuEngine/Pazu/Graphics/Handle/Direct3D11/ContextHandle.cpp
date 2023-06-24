#include "Shader/VertexShaderHandle.h"
#include "Shader/PixelShaderHandle.h"
#include "../../Vertex/VertexPositionNormalColorTexture.h"
#include "../../Vertex/VertexPositionNormalColorTextureSkinning.h"
#include "Buffer/VertexBufferHandle.h"
#include "Buffer/IndexBufferHandle.h"
#include "Buffer/ConstantBufferHandle.h"
#include "InputLayout/VertexInputLayoutHandle.h"
#include "SamplerState/SamplerStateHandle.h"
#include "Texture/Texture2DHandle.h"
#include "BlendState/BlendStateHandle.h"
#include "../../../WindowHandle.h"
#include "DeviceHandle.h"
#include "ContextHandle.h"
using namespace magic_enum::flags;

namespace Pazu::Graphics::Direct3D11
{
	ContextHandle::ContextHandle(const std::shared_ptr<DeviceHandle> &device, const std::shared_ptr<WindowHandle> &window, const ContextConfig &config)
			: m_device(device), m_window(window), m_config(config), m_context(m_device->CreateImmediateContext()),
				m_rasterizerStates{m_device->CreateRasterizerState(false, D3D11_CULL_BACK), m_device->CreateRasterizerState(false, D3D11_CULL_NONE), m_device->CreateRasterizerState(true, D3D11_CULL_NONE)},
				m_depthStencilStates{m_device->CreateDepthStencilState(), m_device->CreateDepthStencilState(true, D3D11_DEPTH_WRITE_MASK_ZERO)},
				m_presentFlags(m_device->GetFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING) ? DXGI_PRESENT_ALLOW_TEARING : 0)
	{
		CreateWindowDependents();
		SetClearColor(Color::CornflowerBlue);
		SetClearFlags(ClearFlag::Depth | ClearFlag::Stencil);
	}

	void ContextHandle::Resize(const Size &size)
	{
		DestroyWindowSizeDependents();
		if (HRESULT hResult; FAILED(hResult = m_swapChain->ResizeBuffers(m_swapChainDesc.BufferCount, size.Width(), size.Height(), m_backBufferDesc.Format, m_swapChainDesc.Flags)))
			WLog::Get().Print<LogMode::Error>(L"Bufferlar yeniden boyutlandirilamadi. " + Log::Get().ToString(hResult));
		CreateWindowSizeDependents();
	}

	void ContextHandle::Clear() const
	{
		m_context->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);
		m_context->ClearRenderTargetView(m_renderTargetView, m_clearColor);
		m_context->ClearDepthStencilView(m_depthStencilView, m_clearFlags, 1.f, 0);
	}

	void ContextHandle::Draw(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const
	{
		m_context->RSSetState(m_rasterizerStates[m_rasterizerStateIndex]);
		m_context->Draw(vertexBuffer.GetSize(), 0);
	}

	void ContextHandle::Draw(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const
	{
		m_context->RSSetState(m_rasterizerStates[m_rasterizerStateIndex]);
		m_context->Draw(vertexBuffer.GetSize(), 0);
	}

	void ContextHandle::Draw(const IndexBuffer<unsigned int> &indexBuffer) const
	{
		m_context->RSSetState(m_rasterizerStates[m_rasterizerStateIndex]);
		m_context->DrawIndexed(indexBuffer.GetSize(), 0, 0);
	}

	void ContextHandle::Present() const
	{
		static constexpr DXGI_PRESENT_PARAMETERS paramaters = {};
		if (auto hResult = m_swapChain->Present1(m_syncInterval, (m_presentFlags * -(m_syncInterval - 1)) * m_windowed, &paramaters); FAILED(hResult))
			WLog::Get().Print<LogMode::Error>(L"SwapChain buffer present edilemedi. " + Log::Get().ToString(hResult));
	}

	void ContextHandle::CreateWindowDependents()
	{
		m_swapChain = m_device->CreateSwapChain(*m_window, m_config.GetBufferCount());
		m_swapChain->GetDesc1(&m_swapChainDesc);
		CreateWindowSizeDependents();
	}

	void ContextHandle::DestroyWindowDependents()
	{
		m_swapChain.Reset();
		DestroyWindowSizeDependents();
	}

	void ContextHandle::CreateWindowSizeDependents()
	{
		m_backBuffer = m_device->CreateBackBuffer(m_swapChain);
		m_backBuffer->GetDesc(&m_backBufferDesc);
		m_renderTargetView = m_device->CreateRenderTargetView(m_backBuffer);
		m_depthStencilBuffer = m_device->CreateDepthStencilBuffer({m_backBufferDesc.Width, m_backBufferDesc.Height});
		m_depthStencilView = m_device->CreateDepthStencilView(m_depthStencilBuffer);
		SetViewport({0.f, 0.f, static_cast<float>(m_backBufferDesc.Width), static_cast<float>(m_backBufferDesc.Height)});
	}

	void ContextHandle::DestroyWindowSizeDependents()
	{
		constexpr std::array<ID3D11RenderTargetView *, 1> nullRenderTargetViews = {nullptr};
		m_context->OMSetRenderTargets(nullRenderTargetViews.size(), nullRenderTargetViews.data(), nullptr);
		m_renderTargetView.Reset();
		m_depthStencilView.Reset();
		m_backBuffer.Reset();
		m_depthStencilBuffer.Reset();
		m_context->Flush();
	}

	DrawMode ContextHandle::GetDrawMode() const
	{
		m_context->IAGetPrimitiveTopology(&m_primitiveTopology);
		switch (m_primitiveTopology)
		{
		case D3D11_PRIMITIVE_TOPOLOGY_POINTLIST:
			return DrawMode::PointList;
		case D3D11_PRIMITIVE_TOPOLOGY_LINELIST:
			return DrawMode::LineList;
		case D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP:
			return DrawMode::LineStrip;
		case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
			return DrawMode::TriangleList;
		case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP:
			return DrawMode::TriangleStrip;
		case D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ:
			return DrawMode::LineListAdj;
		case D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ:
			return DrawMode::LineStripAdj;
		case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ:
			return DrawMode::TriangleListAdj;
		case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ:
			return DrawMode::TriangleStripAdj;
		default:
			break;
		}
		return {};
	}

	bool ContextHandle::GetCullFace() const
	{
		m_rasterizerStates[m_rasterizerStateIndex]->GetDesc1(&m_rasterizerStateDesc);
		switch (m_rasterizerStateDesc.CullMode)
		{
		case D3D11_CULL_BACK:
			return true;
		case D3D11_CULL_NONE:
			return false;
		default:
			break;
		}
		return false;
	}

	bool ContextHandle::GetWireframe() const
	{
		m_rasterizerStates[m_rasterizerStateIndex]->GetDesc1(&m_rasterizerStateDesc);
		return m_rasterizerStateDesc.FillMode == D3D11_FILL_WIREFRAME;
	}

	const Color &ContextHandle::GetClearColor() const
	{
		return m_clearColor;
	}

	ClearFlag ContextHandle::GetClearFlags() const
	{
		ClearFlag clearFlags;
		if (m_clearFlags & D3D11_CLEAR_DEPTH)
			clearFlags |= ClearFlag::Depth;
		if (m_clearFlags & D3D11_CLEAR_STENCIL)
			clearFlags |= ClearFlag::Stencil;
		return clearFlags;
	}

	Size ContextHandle::GetDrawableSize() const
	{
		return {m_backBufferDesc.Width, m_backBufferDesc.Height};
	}

	Viewport ContextHandle::GetViewport() const
	{
		UINT count = 1;
		m_context->RSGetViewports(&count, &m_viewport);
		return {m_viewport.TopLeftX, m_viewport.TopLeftY, m_viewport.Width, m_viewport.Height, m_viewport.MinDepth, m_viewport.MaxDepth};
	}

	bool ContextHandle::GetVsync() const
	{
		return static_cast<bool>(m_syncInterval);
	}

	bool ContextHandle::GetFullscreen() const
	{
		BOOL fullscreen;
		if (HRESULT hResult; FAILED(hResult = m_swapChain->GetFullscreenState(&fullscreen, nullptr)))
			WLog::Get().Print<LogMode::Error>(L"GraphicsContext Fullscreen durum bilgisi alinamadi. " + Log::Get().ToString(hResult));
		return fullscreen == TRUE;
	}

	const ContextConfig &ContextHandle::GetConfig() const
	{
		return m_config;
	}

	void ContextHandle::SetShader(const VertexShader &vertexShader) const
	{
		m_context->VSSetShader(vertexShader.GetHandle<VertexShaderHandle>()->Get(), nullptr, 0);
	}

	void ContextHandle::SetShader(const PixelShader &pixelShader) const
	{
		m_context->PSSetShader(pixelShader.GetHandle<PixelShaderHandle>()->Get(), nullptr, 0);
	}

	void ContextHandle::SetBuffer(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const
	{
		const auto vbHandle = vertexBuffer.GetHandle<VertexBufferHandle>();
		const auto stride = static_cast<UINT>(vertexBuffer.GetStride());
		constexpr UINT offset = 0;
		m_context->IASetVertexBuffers(0, 1, &vbHandle->Get(), &stride, &offset);
	}

	void ContextHandle::SetBuffer(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const
	{
		const auto vbHandle = vertexBuffer.GetHandle<VertexBufferHandle>();
		const auto stride = static_cast<UINT>(vertexBuffer.GetStride());
		constexpr UINT offset = 0;
		m_context->IASetVertexBuffers(0, 1, &vbHandle->Get(), &stride, &offset);
	}

	void ContextHandle::SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const
	{
		m_context->IASetIndexBuffer(indexBuffer.GetHandle<IndexBufferHandle>()->Get(), DXGI_FORMAT_R32_UINT, 0);
	}

	void ContextHandle::SetBuffer(const ConstantBuffer &constantBuffer) const
	{
		const auto cbHandle = constantBuffer.GetHandle<ConstantBufferHandle>();
		if ((constantBuffer.GetShaderFlags() & ShaderFlag::Vertex) == ShaderFlag::Vertex)
			m_context->VSSetConstantBuffers1(constantBuffer.GetSlotIndex(), 1, &cbHandle->Get(), nullptr, nullptr);
		if ((constantBuffer.GetShaderFlags() & ShaderFlag::Pixel) == ShaderFlag::Pixel)
			m_context->PSSetConstantBuffers1(constantBuffer.GetSlotIndex(), 1, &cbHandle->Get(), nullptr, nullptr);
	}

	void ContextHandle::UpdateBuffer(const ConstantBuffer &constantBuffer) const
	{
		const auto cbHandle = constantBuffer.GetHandle<ConstantBufferHandle>();
		m_context->UpdateSubresource1(cbHandle->Get(), 0, nullptr, cbHandle->GetData().pSysMem, 0, 0, 0);
	}

	void ContextHandle::SetInputLayout(const VertexInputLayout &layout) const
	{
		m_context->IASetInputLayout(layout.GetHandle<VertexInputLayoutHandle>()->Get());
	}

	void ContextHandle::SetSamplerState(const SamplerState &samplerState) const
	{
		m_context->PSSetSamplers(0, 1, &samplerState.GetHandle<SamplerStateHandle>()->Get());
	}

	void ContextHandle::SetTexture(const Texture2D &texture2d) const
	{
		m_context->PSSetShaderResources(0, 1, &texture2d.GetHandle<Texture2DHandle>()->GetShaderResourceView());
	}

	void ContextHandle::SetBlendState(const BlendState &blendState) const
	{
		m_context->OMSetDepthStencilState(m_depthStencilStates[blendState.GetEnable()], 1);
		m_context->OMSetBlendState(blendState.GetHandle<BlendStateHandle>()->Get(), blendState.GetFactor(), 0xffffffff);
	}

	void ContextHandle::SetDrawMode(const DrawMode drawMode)
	{
		switch (drawMode)
		{
		case DrawMode::PointList:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
		case DrawMode::LineList:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
		case DrawMode::LineStrip:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
		case DrawMode::TriangleList:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		case DrawMode::TriangleStrip:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
		case DrawMode::LineListAdj:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ);
		case DrawMode::LineStripAdj:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ);
		case DrawMode::TriangleListAdj:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ);
		case DrawMode::TriangleStripAdj:
			return m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ);
		default:
			return;
		}
	}

	void ContextHandle::SetCullFace(const bool cullFace)
	{
		if (!GetWireframe())
			m_rasterizerStateIndex = cullFace ? 0 : 1;
	}

	void ContextHandle::SetWireframe(const bool wireframe)
	{
		m_rasterizerStateIndex = wireframe ? 2 : 0;
	}

	void ContextHandle::SetClearColor(const Color &color)
	{
		m_clearColor = color;
	}

	void ContextHandle::SetClearFlags(const ClearFlag flags)
	{
		m_clearFlags = 0;
		if (enum_integer(flags & ClearFlag::Depth))
			m_clearFlags |= D3D11_CLEAR_DEPTH;
		if (enum_integer(flags & ClearFlag::Stencil))
			m_clearFlags |= D3D11_CLEAR_STENCIL;
	}

	void ContextHandle::SetViewport(const Viewport &viewport) const
	{
		const D3D11_VIEWPORT v = {viewport.x, viewport.y, viewport.width, viewport.height, viewport.minDepth, viewport.maxDepth};
		m_context->RSSetViewports(1, &v);
	}

	void ContextHandle::SetVsync(const bool vsync)
	{
		m_syncInterval = vsync ? 1 : 0;
	}

	void ContextHandle::SetFullscreen(const bool fullscreen)
	{
		DXGI_MODE_DESC scResizeDesc = {};
		scResizeDesc.Width = m_backBufferDesc.Width;
		scResizeDesc.Height = m_backBufferDesc.Height;
		scResizeDesc.Format = m_swapChainDesc.Format;
		m_swapChain->ResizeTarget(&scResizeDesc);
		if (HRESULT hResult; FAILED(hResult = m_swapChain->SetFullscreenState(fullscreen ? TRUE : FALSE, nullptr)))
			return WLog::Get().Print<LogMode::Error>(L"GraphicsContext Fullscreen durumu ayarlanamadi. " + Log::Get().ToString(hResult));
		m_windowed = static_cast<UINT>(!fullscreen);
	}

	void ContextHandle::SetWindow(const std::shared_ptr<WindowHandle> &window)
	{
		m_window = window;
		DestroyWindowDependents();
		CreateWindowDependents();
	}

	void ContextHandle::SetConfig(const ContextConfig &config)
	{
		m_config = config;
		DestroyWindowDependents();
		CreateWindowDependents();
	}
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Math/Color.h"
#include "../../ContextConfig.h"
#include "../../IContextHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class DeviceHandle;
	class ContextHandle : public IContextHandle
	{
	public:
		ContextHandle(const std::shared_ptr<DeviceHandle> &device, const std::shared_ptr<WindowHandle> &window, const ContextConfig &config);
		void Resize(const Size &size) final;
		void Clear() const final;
		void Draw(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const final;
		void Draw(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const final;
		void Draw(const IndexBuffer<unsigned int> &indexBuffer) const final;
		void Present() const final;
		DrawMode GetDrawMode() const final;
		bool GetCullFace() const final;
		bool GetWireframe() const final;
		const Color &GetClearColor() const final;
		ClearFlag GetClearFlags() const final;
		Size GetDrawableSize() const final;
		Viewport GetViewport() const final;
		bool GetVsync() const final;
		bool GetFullscreen() const final;
		const ContextConfig &GetConfig() const final;
		void SetShader(const VertexShader &vertexShader) const final;
		void SetShader(const PixelShader &pixelShader) const final;
		void SetBuffer(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const final;
		void SetBuffer(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const final;
		void SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const final;
		void SetBuffer(const ConstantBuffer &constantBuffer) const final;
		void UpdateBuffer(const ConstantBuffer &constantBuffer) const final;
		void SetInputLayout(const VertexInputLayout &layout) const final;
		void SetSamplerState(const SamplerState &samplerState) const final;
		void SetTexture(const Texture2D &texture2d) const final;
		void SetBlendState(const BlendState &blendState) const final;
		void SetDrawMode(const DrawMode drawMode) final;
		void SetCullFace(const bool cullFace) final;
		void SetWireframe(const bool wireframe) final;
		void SetClearColor(const Color &color) final;
		void SetClearFlags(const ClearFlag flags) final;
		void SetViewport(const Viewport &viewport) const final;
		void SetVsync(const bool vsync) final;
		void SetFullscreen(const bool fullscreen) final;
		void SetWindow(const std::shared_ptr<WindowHandle> &window) final;
		void SetConfig(const ContextConfig &config) final;

	private:
		void CreateWindowDependents();
		void DestroyWindowDependents();
		void CreateWindowSizeDependents();
		void DestroyWindowSizeDependents();

		const std::shared_ptr<DeviceHandle> m_device;
		std::shared_ptr<WindowHandle> m_window;
		ContextConfig m_config;
		const UniqueComPtr<ID3D11DeviceContext1> m_context;
		UniqueComPtr<IDXGISwapChain1> m_swapChain;
		UniqueComPtr<ID3D11Texture2D> m_backBuffer;
		UniqueComPtr<ID3D11RenderTargetView> m_renderTargetView;
		UniqueComPtr<ID3D11DepthStencilView> m_depthStencilView;
		UniqueComPtr<ID3D11Texture2D> m_depthStencilBuffer;
		const std::array<UniqueComPtr<ID3D11RasterizerState1>, 3> m_rasterizerStates;
		const std::array<UniqueComPtr<ID3D11DepthStencilState>, 2> m_depthStencilStates;
		DXGI_SWAP_CHAIN_DESC1 m_swapChainDesc;
		D3D11_TEXTURE2D_DESC m_backBufferDesc;
		mutable D3D11_RASTERIZER_DESC1 m_rasterizerStateDesc;
		std::size_t m_rasterizerStateIndex{0};
		mutable D3D11_PRIMITIVE_TOPOLOGY m_primitiveTopology;
		mutable D3D11_VIEWPORT m_viewport;
		Color m_clearColor;
		UINT m_clearFlags;
		UINT m_syncInterval{1};
		const UINT m_presentFlags;
		UINT m_windowed{1};
	};
}

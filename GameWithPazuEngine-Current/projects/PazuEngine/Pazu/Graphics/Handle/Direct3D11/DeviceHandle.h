#pragma once
#include "../../IDeviceHandle.h"

namespace Pazu
{
	class WindowHandle;
}
namespace Pazu::Graphics::Direct3D11
{
	class DeviceHandle : public IDeviceHandle
	{
	public:
		DeviceHandle();
		UniqueComPtr<ID3D11DeviceContext1> CreateImmediateContext() const;
		UniqueComPtr<IDXGISwapChain1> CreateSwapChain(const WindowHandle &windowHandle, const unsigned int bufferCount) const;
		UniqueComPtr<ID3D11Texture2D> CreateBackBuffer(const UniqueComPtr<IDXGISwapChain1> &swapChain) const;
		UniqueComPtr<ID3D11RenderTargetView> CreateRenderTargetView(const UniqueComPtr<ID3D11Texture2D> &backBuffer) const;
		UniqueComPtr<ID3D11Texture2D> CreateDepthStencilBuffer(const Size &size) const;
		UniqueComPtr<ID3D11DepthStencilView> CreateDepthStencilView(const UniqueComPtr<ID3D11Texture2D> &depthStencilBuffer) const;
		UniqueComPtr<ID3D11RasterizerState1> CreateRasterizerState(const bool wireframe, const D3D11_CULL_MODE cullMode) const;
		UniqueComPtr<ID3D11DepthStencilState> CreateDepthStencilState(const bool depthEnable = true, const D3D11_DEPTH_WRITE_MASK depthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL, const D3D11_COMPARISON_FUNC comparisonFunc = D3D11_COMPARISON_LESS, const bool stencilEnable = true) const;
		void CreateShader(VertexShader &vertexShader) const final;
		void CreateShader(PixelShader &pixelShader) const final;
		void CreateBuffer(VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const final;
		void CreateBuffer(VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const final;
		void CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const final;
		void CreateBuffer(ConstantBuffer &constantBuffer) const final;
		void CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &vertexInputLayout) const final;
		void CreateSamplerState(SamplerState &samplerState) const final;
		void CreateTexture(Texture2D &texture2d) const final;
		void CreateBlendState(BlendState &blendState) const final;
		bool GetFeatureSupport(const DXGI_FEATURE dxgiFeature) const;
		D3D_FEATURE_LEVEL GetFeatureLevel() const;

	private:
		UniqueComPtr<IDXGIFactory2> m_factory;
		UniqueComPtr<ID3D11Device1> m_device;
		D3D_FEATURE_LEVEL m_featureLevel;
	};
}

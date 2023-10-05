// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../../../WindowHandle.h"
#include "Shader/VertexShaderHandle.h"
#include "Shader/PixelShaderHandle.h"
#include "Buffer/VertexBufferHandle.h"
#include "Buffer/IndexBufferHandle.h"
#include "Buffer/ConstantBufferHandle.h"
#include "InputLayout/VertexInputLayoutHandle.h"
#include "SamplerState/SamplerStateHandle.h"
#include "Texture/Texture2DHandle.h"
#include "BlendState/BlendStateHandle.h"
#include "DeviceHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	DeviceHandle::DeviceHandle()
	{
		{
			UINT deviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if defined(_DEBUG)
			deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
			constexpr std::array<D3D_FEATURE_LEVEL, 1> featureLevels = {D3D_FEATURE_LEVEL_11_1};
			UniqueComPtr<ID3D11Device> device;
			if (HRESULT hResult; FAILED(hResult = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, 0, deviceFlags, featureLevels.data(), featureLevels.size(), D3D11_SDK_VERSION, &device, &m_featureLevel, nullptr)))
				WLog::Get().Print<LogMode::Fatal>(L"Device olusturulamadi. " + Log::Get().ToString(hResult));
			if (HRESULT hResult; FAILED(hResult = device->QueryInterface(IID_PPV_ARGS(&m_device))))
				WLog::Get().Print<LogMode::Fatal>(L"Device alinamadi. " + Log::Get().ToString(hResult));
		}
		UniqueComPtr<IDXGIDevice2> dxgiDevice;
		if (HRESULT hResult; FAILED(hResult = m_device->QueryInterface(IID_PPV_ARGS(&dxgiDevice))))
			WLog::Get().Print<LogMode::Fatal>(L"DXGIDevice alinamadi. " + Log::Get().ToString(hResult));
		if (HRESULT hResult; FAILED(hResult = dxgiDevice->SetMaximumFrameLatency(1)))
			WLog::Get().Print<LogMode::Error>(L"MaximumFrameLatency ayarlanamadi. " + Log::Get().ToString(hResult));
		UniqueComPtr<IDXGIAdapter> dxgiAdapter;
		if (HRESULT hResult; FAILED(hResult = dxgiDevice->GetAdapter(&dxgiAdapter)))
			WLog::Get().Print<LogMode::Fatal>(L"DXGIAdapter alinamadi. " + Log::Get().ToString(hResult));
		if (HRESULT hResult; FAILED(hResult = dxgiAdapter->GetParent(IID_PPV_ARGS(&m_factory))))
			WLog::Get().Print<LogMode::Fatal>(L"DXGIFactory alinamadi. " + Log::Get().ToString(hResult));
	}

	UniqueComPtr<ID3D11DeviceContext1> DeviceHandle::CreateImmediateContext() const
	{
		UniqueComPtr<ID3D11DeviceContext1> context;
		m_device->GetImmediateContext1(&context);
		return context;
	}

	UniqueComPtr<IDXGISwapChain1> DeviceHandle::CreateSwapChain(const WindowHandle &windowHandle, const unsigned int bufferCount) const
	{
		UINT scFlags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		if (GetFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING))
			scFlags |= DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;
		DXGI_SWAP_CHAIN_DESC1 scDesc = {};
		scDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		scDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
		scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scDesc.SampleDesc = {.Count = 1, .Quality = 0};
		scDesc.BufferCount = bufferCount;
		scDesc.Scaling = DXGI_SCALING_NONE;
		scDesc.Flags = scFlags;
		UniqueComPtr<IDXGISwapChain1> dxgiSwapChain;
		if (HRESULT hResult; FAILED(hResult = m_factory->CreateSwapChainForHwnd(m_device, windowHandle.GetInfo().win.window, &scDesc, nullptr, nullptr, &dxgiSwapChain)))
			WLog::Get().Print<LogMode::Fatal>(L"SwapChain olusturulamadi. " + Log::Get().ToString(hResult));
		return dxgiSwapChain;
	}

	UniqueComPtr<ID3D11Texture2D> DeviceHandle::CreateBackBuffer(const UniqueComPtr<IDXGISwapChain1> &swapChain) const
	{
		UniqueComPtr<ID3D11Texture2D> backBuffer;
		if (HRESULT hResult; FAILED(hResult = swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer))))
			WLog::Get().Print<LogMode::Fatal>(L"BackBuffer alinamadi. " + Log::Get().ToString(hResult));
		return backBuffer;
	}

	UniqueComPtr<ID3D11RenderTargetView> DeviceHandle::CreateRenderTargetView(const UniqueComPtr<ID3D11Texture2D> &backBuffer) const
	{
		UniqueComPtr<ID3D11RenderTargetView> renderTargetView;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView)))
			WLog::Get().Print<LogMode::Fatal>(L"RenderTargetView olusturulamadi. " + Log::Get().ToString(hResult));
		return renderTargetView;
	}

	UniqueComPtr<ID3D11Texture2D> DeviceHandle::CreateDepthStencilBuffer(const Size &size) const
	{
		D3D11_TEXTURE2D_DESC dsbDesc = {};
		dsbDesc.Width = size.Width();
		dsbDesc.Height = size.Height();
		dsbDesc.MipLevels = 1;
		dsbDesc.ArraySize = 1;
		dsbDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		dsbDesc.SampleDesc = {.Count = 1, .Quality = 0};
		dsbDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		UniqueComPtr<ID3D11Texture2D> depthStencilBuffer;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateTexture2D(&dsbDesc, nullptr, &depthStencilBuffer)))
			WLog::Get().Print<LogMode::Fatal>(L"DepthStencilBuffer olusturulamadi. " + Log::Get().ToString(hResult));
		return depthStencilBuffer;
	}

	UniqueComPtr<ID3D11DepthStencilView> DeviceHandle::CreateDepthStencilView(const UniqueComPtr<ID3D11Texture2D> &depthStencilBuffer) const
	{
		D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
		dsvDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		UniqueComPtr<ID3D11DepthStencilView> depthStencilView;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateDepthStencilView(depthStencilBuffer, &dsvDesc, &depthStencilView)))
			WLog::Get().Print<LogMode::Fatal>(L"DepthStencilView olusturulamadi. " + Log::Get().ToString(hResult));
		return depthStencilView;
	}

	UniqueComPtr<ID3D11RasterizerState1> DeviceHandle::CreateRasterizerState(const bool wireframe, const D3D11_CULL_MODE cullMode) const
	{
		D3D11_RASTERIZER_DESC1 desc = {};
		desc.FillMode = wireframe ? D3D11_FILL_WIREFRAME : D3D11_FILL_SOLID;
		desc.CullMode = cullMode;
		UniqueComPtr<ID3D11RasterizerState1> rasterizerState;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateRasterizerState1(&desc, &rasterizerState)))
			WLog::Get().Print<LogMode::Fatal>(L"RasterizerState olusturulamadi. " + Log::Get().ToString(hResult));
		return rasterizerState;
	}

	UniqueComPtr<ID3D11DepthStencilState> DeviceHandle::CreateDepthStencilState(const bool depthEnable, const D3D11_DEPTH_WRITE_MASK depthWriteMask, const D3D11_COMPARISON_FUNC comparisonFunc, const bool stencilEnable) const
	{
		D3D11_DEPTH_STENCIL_DESC desc = {};
		desc.DepthEnable = depthEnable;
		desc.DepthWriteMask = depthWriteMask;
		desc.DepthFunc = comparisonFunc;
		desc.StencilEnable = stencilEnable;
		desc.StencilReadMask = 0xFF;
		desc.StencilWriteMask = 0xFF;
		desc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		desc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		desc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		desc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		desc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		desc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		UniqueComPtr<ID3D11DepthStencilState> depthStencilState;
		m_device->CreateDepthStencilState(&desc, &depthStencilState);
		return depthStencilState;
	}

	void DeviceHandle::CreateShader(VertexShader &vertexShader) const
	{
		auto vsHandle = std::make_unique<VertexShaderHandle>(vertexShader);
		UniqueComPtr<ID3D11VertexShader> vs;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateVertexShader(vsHandle->GetByteCode(), vsHandle->GetByteCodeSize(), nullptr, &vs)))
			return WLog::Get().Print<LogMode::Error>(L"VertexShader olusturulamadi. " + Log::Get().ToString(hResult));
		if (!vertexShader.GetCompiled())
			return;
		vsHandle->Set(std::move(vs));
		vertexShader.SetHandle(std::move(vsHandle));
	}

	void DeviceHandle::CreateShader(PixelShader &pixelShader) const
	{
		auto psHandle = std::make_unique<PixelShaderHandle>(pixelShader);
		UniqueComPtr<ID3D11PixelShader> ps;
		if (HRESULT hResult; FAILED(hResult = m_device->CreatePixelShader(psHandle->GetByteCode(), psHandle->GetByteCodeSize(), nullptr, &ps)))
			return WLog::Get().Print<LogMode::Error>(L"PixelShader olusturulamadi. " + Log::Get().ToString(hResult));
		if (!pixelShader.GetCompiled())
			return;
		psHandle->Set(std::move(ps));
		pixelShader.SetHandle(std::move(psHandle));
	}

	void DeviceHandle::CreateBuffer(VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const
	{
		auto vbHandle = std::make_unique<VertexBufferHandle>(vertexBuffer);
		UniqueComPtr<ID3D11Buffer> vb;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateBuffer(&vbHandle->GetDesc(), &vbHandle->GetData(), &vb)))
			return WLog::Get().Print<LogMode::Error>(L"VertexBuffer olusturulamadi. " + Log::Get().ToString(hResult));
		vbHandle->Set(std::move(vb));
		vertexBuffer.SetHandle(std::move(vbHandle));
	}

	void DeviceHandle::CreateBuffer(VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const
	{
		auto vbHandle = std::make_unique<VertexBufferHandle>(vertexBuffer);
		UniqueComPtr<ID3D11Buffer> vb;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateBuffer(&vbHandle->GetDesc(), &vbHandle->GetData(), &vb)))
			return WLog::Get().Print<LogMode::Error>(L"VertexBuffer olusturulamadi. " + Log::Get().ToString(hResult));
		vbHandle->Set(std::move(vb));
		vertexBuffer.SetHandle(std::move(vbHandle));
	}

	void DeviceHandle::CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const
	{
		auto ibHandle = std::make_unique<IndexBufferHandle>(indexBuffer);
		UniqueComPtr<ID3D11Buffer> ib;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateBuffer(&ibHandle->GetDesc(), &ibHandle->GetData(), &ib)))
			return WLog::Get().Print<LogMode::Error>(L"IndexBuffer olusturulamadi. " + Log::Get().ToString(hResult));
		ibHandle->Set(std::move(ib));
		indexBuffer.SetHandle(std::move(ibHandle));
	}

	void DeviceHandle::CreateBuffer(ConstantBuffer &constantBuffer) const
	{
		auto cbHandle = std::make_unique<ConstantBufferHandle>(constantBuffer);
		UniqueComPtr<ID3D11Buffer> cb;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateBuffer(&cbHandle->GetDesc(), &cbHandle->GetData(), &cb)))
			return WLog::Get().Print<LogMode::Error>(L"ConstantBuffer olusturulamadi. " + Log::Get().ToString(hResult));
		cbHandle->Set(std::move(cb));
		constantBuffer.SetHandle(std::move(cbHandle));
	}

	void DeviceHandle::CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &vertexInputLayout) const
	{
		auto vilHandle = std::make_unique<VertexInputLayoutHandle>(vertexInputLayout);
		const auto vsHandle = vertexShader.GetHandle<VertexShaderHandle>();
		const auto &elements = vilHandle->GetElements();
		UniqueComPtr<ID3D11InputLayout> vil;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateInputLayout(elements.data(), elements.size(), vsHandle->GetByteCode(), vsHandle->GetByteCodeSize(), &vil)))
			return WLog::Get().Print<LogMode::Error>(L"VertexInputLayout olusturulamadi. " + Log::Get().ToString(hResult));
		vilHandle->Set(std::move(vil));
		vertexInputLayout.SetHandle(std::move(vilHandle));
	}

	void DeviceHandle::CreateSamplerState(SamplerState &samplerState) const
	{
		auto ssHandle = std::make_unique<SamplerStateHandle>(samplerState);
		UniqueComPtr<ID3D11SamplerState> ss;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateSamplerState(&ssHandle->GetDesc(), &ss)))
			return WLog::Get().Print<LogMode::Error>(L"SamplerState olusturulamadi. " + Log::Get().ToString(hResult));
		ssHandle->Set(std::move(ss));
		samplerState.SetHandle(std::move(ssHandle));
	}

	void DeviceHandle::CreateTexture(Texture2D &texture2d) const
	{
		auto t2dHandle = std::make_unique<Texture2DHandle>(texture2d);
		const auto &t2dData = t2dHandle->GetData();
		UniqueComPtr<ID3D11ShaderResourceView> srv;
		const auto context = CreateImmediateContext();
		if (HRESULT hResult; FAILED(hResult = DirectX::DDSTextureData::CreateTextureFromDDS(m_device, context, t2dData->ddsHeader, t2dData->bitData, t2dData->bitSize, 0, D3D11_USAGE_DEFAULT, D3D11_BIND_SHADER_RESOURCE, 0, 0, false, nullptr, &srv)))
			return WLog::Get().Print<LogMode::Error>(L"Texture2D olusturulamadi. " + Log::Get().ToString(hResult));
		t2dHandle->SetShaderResourceView(std::move(srv));
		texture2d.SetHandle(std::move(t2dHandle));
	}

	void DeviceHandle::CreateBlendState(BlendState &blendState) const
	{
		auto bsHandle = std::make_unique<BlendStateHandle>(blendState);
		UniqueComPtr<ID3D11BlendState1> bs;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateBlendState1(&bsHandle->GetDesc(), &bs)))
			return WLog::Get().Print<LogMode::Error>(L"BlendState olusturulamadi. " + Log::Get().ToString(hResult));
		bsHandle->Set(std::move(bs));
		blendState.SetHandle(std::move(bsHandle));
	}

	bool DeviceHandle::GetFeatureSupport(const DXGI_FEATURE dxgiFeature) const
	{
		UniqueComPtr<IDXGIFactory5> factory5;
		if (HRESULT hResult; FAILED(hResult = m_factory->QueryInterface(IID_PPV_ARGS(&factory5))))
			return WLog::Get().Print<LogMode::Error, bool>(L"DXGIFactory5 alinamadi. " + Log::Get().ToString(hResult));
		BOOL allowTearing;
		if (HRESULT hResult; FAILED(hResult = factory5->CheckFeatureSupport(dxgiFeature, &allowTearing, sizeof(allowTearing))))
			return WLog::Get().Print<LogMode::Error, bool>(L"AllowTearing ozellik destegi bilgisi alinamadi. " + Log::Get().ToString(hResult));
		return static_cast<bool>(allowTearing);
	}

	D3D_FEATURE_LEVEL DeviceHandle::GetFeatureLevel() const
	{
		return m_featureLevel;
	}
}

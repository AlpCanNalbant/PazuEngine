// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../../../WindowHandle.h"
#include "GraphicsDeviceHandle.h"
using namespace Microsoft::WRL;

namespace Pazu::Direct3D12
{
	GraphicsDeviceHandle::GraphicsDeviceHandle() noexcept
	{
#if defined(_DEBUG)
		{
			UniqueComPtr<ID3D12Debug> debugController;
			if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
				debugController->EnableDebugLayer();
		}
#endif
		if (HRESULT hResult; FAILED(hResult = CreateDXGIFactory1(IID_PPV_ARGS(&m_factory))))
			TWLog::Get().Print<LogMode::Fatal>(L"Factory olusturulamadi. " + TWLog::Get().ToString(hResult));
		if (HRESULT hResult; FAILED(hResult = D3D12CreateDevice(FindHardwareAdapter(*m_factory), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device))))
			TWLog::Get().Print<LogMode::Fatal>(L"Device olusturulamadi. " + TWLog::Get().ToString(hResult));
	}

	UniqueComPtr<IDXGIAdapter1> GraphicsDeviceHandle::FindHardwareAdapter(IDXGIFactory1 &factory, const bool highPerformanceAdapter) const noexcept
	{
		UniqueComPtr<IDXGIAdapter1> adapter;
		UniqueComPtr<IDXGIFactory6> factory6;
		if (SUCCEEDED(factory.QueryInterface(IID_PPV_ARGS(&factory6))))
		{
			const auto gpuPreference = highPerformanceAdapter ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED;
			for (UINT x = 0; factory6->EnumAdapterByGpuPreference(x, gpuPreference, IID_PPV_ARGS(&adapter)) != DXGI_ERROR_NOT_FOUND; ++x)
			{
				DXGI_ADAPTER_DESC1 desc;
				adapter->GetDesc1(&desc);
				if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
					continue;
				// Direct3D12 destekleyen adapter'u kontrol et ama device'i henuz yaratma
				if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
					break;
			}
		}
		else
		{
			for (UINT x = 0; factory.EnumAdapters1(x, &adapter) != DXGI_ERROR_NOT_FOUND; ++x)
			{
				DXGI_ADAPTER_DESC1 desc;
				adapter->GetDesc1(&desc);
				if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
					continue;
				// Direct3D12 destekleyen adapter'u kontrol et ama device'i henuz yaratma
				if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
					break;
			}
		}
		return adapter;
	}

	UniqueComPtr<ID3D12CommandQueue> GraphicsDeviceHandle::CreateCommandQueue() const noexcept
	{
		D3D12_COMMAND_QUEUE_DESC queueDesc = {};
		queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		UniqueComPtr<ID3D12CommandQueue> commandQueue;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&commandQueue))))
			TWLog::Get().Print<LogMode::Fatal>(L"CommandQueue olusturulamadi. " + TWLog::Get().ToString(hResult));
		return commandQueue;
	}

	UniqueComPtr<IDXGISwapChain3> GraphicsDeviceHandle::CreateSwapChain(const WindowHandle &windowHandle, ID3D12CommandQueue &commandQueue) const noexcept
	{
		const auto windowSize = windowHandle.GetSize();
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
		swapChainDesc.BufferCount = FrameCount;
		swapChainDesc.BufferDesc.Width = windowSize.Width();
		swapChainDesc.BufferDesc.Height = windowSize.Height();
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferUsage = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapChainDesc.OutputWindow = windowHandle.GetInfo().win.window;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.Windowed = TRUE;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		UniqueComPtr<IDXGISwapChain> swapChain;
		if (HRESULT hResult; FAILED(hResult = m_factory->CreateSwapChain(&commandQueue, &swapChainDesc, &swapChain)))
			TWLog::Get().Print<LogMode::Fatal>(L"SwapChain olusturulamadi. " + TWLog::Get().ToString(hResult));
		UniqueComPtr<IDXGISwapChain3> swapChain3;
		if (HRESULT hResult; FAILED(hResult = swapChain->QueryInterface(&swapChain)))
			TWLog::Get().Print<LogMode::Fatal>(L"SwapChain arayuzu alinamadi. " + TWLog::Get().ToString(hResult));
		return swapChain3;
	}

	UniqueComPtr<ID3D12DescriptorHeap> GraphicsDeviceHandle::CreateRtvDescriptorHeap() const noexcept
	{
		D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
		rtvHeapDesc.NumDescriptors = FrameCount;
		rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		UniqueComPtr<ID3D12DescriptorHeap> descriptorHeap;
		if (HRESULT hResult; FAILED(hResult = m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&descriptorHeap))))
			TWLog::Get().Print<LogMode::Fatal>(L"DescriptorHeap olusturulamadi. " + TWLog::Get().ToString(hResult));
		return descriptorHeap;
	}

	std::array<UniqueComPtr<ID3D12Resource>, 3> GraphicsDeviceHandle::CreateRenderTargetViews(ID3D12DescriptorHeap &rtvDescriptorHeap, IDXGISwapChain3 &swapChain) const noexcept
	{
		const auto rtvDescriptorSize = GetRtvDescriptorHandleIncrementSize();
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(rtvDescriptorHeap.GetCPUDescriptorHandleForHeapStart());
		std::array<UniqueComPtr<ID3D12Resource>, 3> renderTargetViews;
		for (UINT x = 0; x < renderTargetViews.size(); x++)
		{
			if (HRESULT hResult; FAILED(hResult = swapChain.GetBuffer(x, IID_PPV_ARGS(&renderTargetViews[x]))))
				TWLog::Get().Print<LogMode::Fatal>(L"SwapChain back buffer alinamadi. " + TWLog::Get().ToString(hResult));
			m_device->CreateRenderTargetView(renderTargetViews[x], nullptr, rtvHandle);
			rtvHandle.Offset(1, rtvDescriptorSize);
		}
	}

	UniqueComPtr<ID3D12CommandAllocator> GraphicsDeviceHandle::CreateCommandAllocator() const noexcept
	{
		UniqueComPtr<ID3D12CommandAllocator> commandAllocator;
		if (HRESULT hResult; hResult = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandAllocator)))
			TWLog::Get().Print<LogMode::Fatal>(L"CommandAllocator olusturulamadi. " + TWLog::Get().ToString(hResult));
		return commandAllocator;
	}

	UniqueComPtr<ID3D12GraphicsCommandList> GraphicsDeviceHandle::CreateCommandList(ID3D12CommandAllocator &commandAllocator) const noexcept
	{
		UniqueComPtr<ID3D12GraphicsCommandList> commandList;
		if (HRESULT hResult; hResult = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, &commandAllocator, nullptr, IID_PPV_ARGS(&commandList)))
			TWLog::Get().Print<LogMode::Fatal>(L"CommandList olusturulamadi. " + TWLog::Get().ToString(hResult));
		commandList->Close();
		return commandList;
	}

	UniqueComPtr<ID3D12Fence> GraphicsDeviceHandle::CreateFence() const noexcept
	{
		UniqueComPtr<ID3D12Fence> fence;
		if (HRESULT hResult; hResult = m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence)))
			TWLog::Get().Print<LogMode::Fatal>(L"Fence olusturulamadi. " + TWLog::Get().ToString(hResult));
		return fence;
	}

	HANDLE GraphicsDeviceHandle::CreateFenceEvent() const noexcept
	{
		auto fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
		if (!fenceEvent)
			TWLog::Get().Print<LogMode::Fatal>(L"FenceEvent olusturulamadi. " + TWLog::Get().ToString(HRESULT_FROM_WIN32(GetLastError())));
		return fenceEvent;
	}

	void GraphicsDeviceHandle::CreateShader(VertexShader &vertexShader) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateShader(PixelShader &pixelShader) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateBuffer(VertexBuffer<float> &vertexBuffer) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateBuffer(ConstantBuffer &constantBuffer) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &inputLayout) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateSamplerState(SamplerState &samplerState) const noexcept
	{
	}

	void GraphicsDeviceHandle::CreateTexture(Texture2D &texture2d) const noexcept
	{
	}

	UINT GraphicsDeviceHandle::GetRtvDescriptorHandleIncrementSize() const noexcept
	{
		return m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	}
}

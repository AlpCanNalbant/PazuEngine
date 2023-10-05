// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../IGraphicsDeviceHandle.h"

namespace Pazu
{
	class WindowHandle;
}
namespace Pazu::Direct3D12
{
	class GraphicsContextHandle;
	class GraphicsDeviceHandle : public IGraphicsDeviceHandle
	{
	public:
		GraphicsDeviceHandle() noexcept;
		UniqueComPtr<ID3D12CommandQueue> CreateCommandQueue() const noexcept;
		UniqueComPtr<IDXGISwapChain3> CreateSwapChain(const WindowHandle &windowHandle, ID3D12CommandQueue &commandQueue) const noexcept;
		UniqueComPtr<ID3D12DescriptorHeap> CreateRtvDescriptorHeap() const noexcept;
		std::array<UniqueComPtr<ID3D12Resource>, 3> CreateRenderTargetViews(ID3D12DescriptorHeap &rtvDescriptorHeap, IDXGISwapChain3 &swapChain) const noexcept;
		UniqueComPtr<ID3D12CommandAllocator> CreateCommandAllocator() const noexcept;
		UniqueComPtr<ID3D12GraphicsCommandList> CreateCommandList(ID3D12CommandAllocator &commandAllocator) const noexcept;
		UniqueComPtr<ID3D12Fence> CreateFence() const noexcept;
		HANDLE CreateFenceEvent() const noexcept;
		void CreateShader(VertexShader &vertexShader) const noexcept final;
		void CreateShader(PixelShader &pixelShader) const noexcept final;
		void CreateBuffer(VertexBuffer<float> &vertexBuffer) const noexcept final;
		void CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const noexcept final;
		void CreateBuffer(ConstantBuffer &constantBuffer) const noexcept final;
		void CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &inputLayout) const noexcept final;
		void CreateSamplerState(SamplerState &samplerState) const noexcept final;
		void CreateTexture(Texture2D &texture2d) const noexcept final;
		UINT GetRtvDescriptorHandleIncrementSize() const noexcept;

	private:
		UniqueComPtr<IDXGIAdapter1> FindHardwareAdapter(IDXGIFactory1 &factory, const bool highPerformanceAdapter = false) const noexcept;

		UniqueComPtr<IDXGIFactory4> m_factory;
		UniqueComPtr<ID3D12Device> m_device;
	};
}

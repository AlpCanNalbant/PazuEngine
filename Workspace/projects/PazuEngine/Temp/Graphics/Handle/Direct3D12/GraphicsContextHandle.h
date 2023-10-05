// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../IGraphicsContextHandle.h"

namespace Pazu::Direct3D12
{
	class GraphicsDeviceHandle;
	class GraphicsContextHandle : public IGraphicsContextHandle
	{
	public:
		GraphicsContextHandle(const std::shared_ptr<GraphicsDeviceHandle> &device, const std::shared_ptr<WindowHandle> &window, const GraphicsContextConfig &config) noexcept;
		void Resize(const Size &size) noexcept final;
		void Clear() const noexcept final;
		void Draw(const VertexBuffer<float> &vertexBuffer) const noexcept final;
		void Draw(const IndexBuffer<unsigned int> &indexBuffer) const noexcept final;
		void Present() const noexcept final;
		DrawMode GetDrawMode() const noexcept final;
		bool GetCullFace() const noexcept final;
		bool GetWireframe() const noexcept final;
		const Color &GetClearColor() const noexcept final;
		ClearFlag GetClearFlags() const noexcept final;
		Size GetDrawableSize() const noexcept final;
		Viewport GetViewport() const noexcept final;
		bool GetVsync() const noexcept final;
		bool GetFullscreen() const noexcept final;
		const GraphicsContextConfig &GetConfig() const noexcept final;
		void SetShader(const VertexShader &vertexShader) const noexcept final;
		void SetShader(const PixelShader &pixelShader) const noexcept final;
		void SetBuffer(const VertexBuffer<float> &vertexBuffer) const noexcept final;
		void SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const noexcept final;
		void SetBuffer(const ConstantBuffer &constantBuffer) const noexcept final;
		void UpdateBufferObject(const ConstantBufferObject &constantBufferObject) const noexcept final;
		void SetInputLayout(const VertexInputLayout &vertexInputLayout) const noexcept final;
		void SetSamplerState(const SamplerState &samplerState) const noexcept final;
		void SetTexture(const Texture2D &texture2d) const noexcept final;
		void SetDrawMode(const DrawMode drawMode) noexcept final;
		void SetCullFace(const bool cullFace) noexcept final;
		void SetWireframe(const bool wireframe) noexcept final;
		void SetClearColor(const Color &color) noexcept final;
		void SetClearFlags(const ClearFlag flags) noexcept final;
		void SetViewport(const Viewport &viewport) const noexcept final;
		void SetVsync(const bool vsync) noexcept final;
		void SetFullscreen(const bool fullscreen) noexcept final;
		void SetWindow(const std::shared_ptr<WindowHandle> &window) noexcept final;
		void SetConfig(const GraphicsContextConfig &config) noexcept final;

	private:
		static constexpr std::size_t FrameCount = 3;
		const std::shared_ptr<GraphicsDeviceHandle> m_device;
		D3D12_VIEWPORT m_viewport;
		D3D12_RECT m_scissorRect;
		UniqueComPtr<IDXGISwapChain3> m_swapChain;
		std::vector<UniqueComPtr<ID3D12Resource>> m_renderTargets;
		UniqueComPtr<ID3D12CommandAllocator> m_commandAllocator;
		UniqueComPtr<ID3D12CommandQueue> m_commandQueue;
		UniqueComPtr<ID3D12RootSignature> m_rootSignature;
		UniqueComPtr<ID3D12DescriptorHeap> m_rtvHeap;
		UniqueComPtr<ID3D12PipelineState> m_pipelineState;
		UniqueComPtr<ID3D12GraphicsCommandList> m_commandList;
		UINT m_rtvDescriptorSize;
		UINT m_frameIndex;
		HANDLE m_fenceEvent;
		UniqueComPtr<ID3D12Fence> m_fence;
		std::array<UINT64, FrameCount> m_fenceValues;
	};
}

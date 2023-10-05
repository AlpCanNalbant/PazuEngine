// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../../../Math/Color.h"
#include "../../GraphicsContextConfig.h"
#include "GraphicsContextHandle.h"

namespace Pazu::Direct3D12
{
	GraphicsContextHandle::GraphicsContextHandle(const std::shared_ptr<GraphicsDeviceHandle> &device, const std::shared_ptr<WindowHandle> &window, const GraphicsContextConfig &config) noexcept
	{
	}

	void GraphicsContextHandle::Resize(const Size &size) noexcept
	{
	}

	void GraphicsContextHandle::Clear() const noexcept
	{
	}

	void GraphicsContextHandle::Draw(const VertexBuffer<float> &vertexBuffer) const noexcept
	{
	}

	void GraphicsContextHandle::Draw(const IndexBuffer<unsigned int> &indexBuffer) const noexcept
	{
	}

	void GraphicsContextHandle::Present() const noexcept
	{
	}

	DrawMode GraphicsContextHandle::GetDrawMode() const noexcept
	{
		return DrawMode::TriangleList;
	}

	bool GraphicsContextHandle::GetCullFace() const noexcept
	{
		return false;
	}

	bool GraphicsContextHandle::GetWireframe() const noexcept
	{
		return false;
	}

	const Color &GraphicsContextHandle::GetClearColor() const noexcept
	{
		return Color::Black;
	}

	ClearFlag GraphicsContextHandle::GetClearFlags() const noexcept
	{
		return ClearFlag::Color | ClearFlag::Depth | ClearFlag::Stencil;
	}

	Size GraphicsContextHandle::GetDrawableSize() const noexcept
	{
		return Size::Zero;
	}

	Viewport GraphicsContextHandle::GetViewport() const noexcept
	{
		return {};
	}

	bool GraphicsContextHandle::GetVsync() const noexcept
	{
		return false;
	}

	bool GraphicsContextHandle::GetFullscreen() const noexcept
	{
		return false;
	}

	const GraphicsContextConfig &GraphicsContextHandle::GetConfig() const noexcept
	{
		return {};
	}

	void GraphicsContextHandle::SetShader(const VertexShader &vertexShader) const noexcept
	{
	}

	void GraphicsContextHandle::SetShader(const PixelShader &pixelShader) const noexcept
	{
	}

	void GraphicsContextHandle::SetBuffer(const VertexBuffer<float> &vertexBuffer) const noexcept
	{
	}

	void GraphicsContextHandle::SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const noexcept
	{
	}

	void GraphicsContextHandle::SetBuffer(const ConstantBuffer &constantBuffer) const noexcept
	{
	}

	void GraphicsContextHandle::UpdateBufferObject(const ConstantBufferObject &constantBufferObject) const noexcept
	{
	}

	void GraphicsContextHandle::SetInputLayout(const VertexInputLayout &vertexInputLayout) const noexcept
	{
	}

	void GraphicsContextHandle::SetSamplerState(const SamplerState &samplerState) const noexcept
	{
	}

	void GraphicsContextHandle::SetTexture(const Texture2D &texture2d) const noexcept
	{
	}

	void GraphicsContextHandle::SetDrawMode(const DrawMode drawMode) noexcept
	{
	}

	void GraphicsContextHandle::SetCullFace(const bool cullFace) noexcept
	{
	}

	void GraphicsContextHandle::SetWireframe(const bool wireframe) noexcept
	{
	}

	void GraphicsContextHandle::SetClearColor(const Color &color) noexcept
	{
	}

	void GraphicsContextHandle::SetClearFlags(const ClearFlag flags) noexcept
	{
	}

	void GraphicsContextHandle::SetViewport(const Viewport &viewport) const noexcept
	{
	}

	void GraphicsContextHandle::SetVsync(const bool vsync) noexcept
	{
	}

	void GraphicsContextHandle::SetFullscreen(const bool fullscreen) noexcept
	{
	}

	void GraphicsContextHandle::SetWindow(const std::shared_ptr<WindowHandle> &window) noexcept
	{
	}

	void GraphicsContextHandle::SetConfig(const GraphicsContextConfig &config) noexcept
	{
	}
}

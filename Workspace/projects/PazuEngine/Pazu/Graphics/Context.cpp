#include "../WindowHandle.h"
#include "../Window.h"
#include "ContextConfig.h"
#include "Handle/Direct3D11/DeviceHandle.h"
#include "Handle/Direct3D11/ContextHandle.h"
#include "Device.h"
#include "Context.h"

namespace Pazu::Graphics
{
	Context::Context(const std::shared_ptr<Device> &device, const std::shared_ptr<Window> &window, const ContextConfig &config)
			: m_device(device), m_window(window), m_config(config)
	{
		switch (Engine::GetGraphicsApi())
		{
		case Api::Direct3D11:
			m_handle = std::make_shared<Direct3D11::ContextHandle>(m_device->GetHandle<Direct3D11::DeviceHandle>(), m_window->GetHandle(), m_config);
			m_window->GetHandle()->SetGraphicsContext(m_handle);
			break;
		case Api::OpenGL:
			break;
		default:
			break;
		}
	}

	void Context::Resize(const Size &size) const
	{
		m_handle->Resize(size);
	}

	void Context::Clear() const
	{
		m_handle->Clear();
	}

	void Context::Draw(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const
	{
		m_handle->Draw(vertexBuffer);
	}

	void Context::Draw(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const
	{
		m_handle->Draw(vertexBuffer);
	}

	void Context::Draw(const IndexBuffer<unsigned int> &indexBuffer) const
	{
		m_handle->Draw(indexBuffer);
	}

	void Context::Present() const
	{
		m_handle->Present();
	}

	DrawMode Context::GetDrawMode() const
	{
		return m_handle->GetDrawMode();
	}

	bool Context::GetCullFace() const
	{
		return m_handle->GetCullFace();
	}

	bool Context::GetWireframe() const
	{
		return m_handle->GetWireframe();
	}

	const Color &Context::GetClearColor() const
	{
		return m_handle->GetClearColor();
	}

	ClearFlag Context::GetClearFlags() const
	{
		return m_handle->GetClearFlags();
	}

	Size Context::GetDrawableSize() const
	{
		return m_handle->GetDrawableSize();
	}

	Viewport Context::GetViewport() const
	{
		return m_handle->GetViewport();
	}

	bool Context::GetVsync() const
	{
		return m_handle->GetVsync();
	}

	const std::shared_ptr<Window> &Context::GetWindow() const
	{
		return m_window;
	}

	const ContextConfig &Context::GetConfig() const
	{
		return m_handle->GetConfig();
	}

	void Context::SetShader(const VertexShader &vertexShader) const
	{
		m_handle->SetShader(vertexShader);
	}

	void Context::SetShader(const PixelShader &pixelShader) const
	{
		m_handle->SetShader(pixelShader);
	}

	void Context::SetBuffer(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const
	{
		m_handle->SetBuffer(vertexBuffer);
	}

	void Context::SetBuffer(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const
	{
		m_handle->SetBuffer(vertexBuffer);
	}

	void Context::SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const
	{
		m_handle->SetBuffer(indexBuffer);
	}

	void Context::SetBuffer(const ConstantBuffer &constantBuffer) const
	{
		m_handle->SetBuffer(constantBuffer);
	}

	void Context::UpdateBuffer(const ConstantBuffer &constantBuffer) const
	{
		m_handle->UpdateBuffer(constantBuffer);
	}

	void Context::SetInputLayout(const VertexInputLayout &layout) const
	{
		m_handle->SetInputLayout(layout);
	}

	void Context::SetSamplerState(const SamplerState &samplerState) const
	{
		m_handle->SetSamplerState(samplerState);
	}

	void Context::SetTexture(const Texture2D &texture2d) const
	{
		m_handle->SetTexture(texture2d);
	}

	void Context::SetBlendState(const BlendState &blendState) const
	{
		m_handle->SetBlendState(blendState);
	}

	void Context::SetDrawMode(const DrawMode drawMode) const
	{
		m_handle->SetDrawMode(drawMode);
	}

	void Context::SetCullFace(const bool cullFace) const
	{
		m_handle->SetCullFace(cullFace);
	}

	void Context::SetWireframe(const bool wireframe) const
	{
		m_handle->SetWireframe(wireframe);
	}

	void Context::SetClearColor(const Color &color) const
	{
		m_handle->SetClearColor(color);
	}

	void Context::SetClearFlags(const ClearFlag flags) const
	{
		m_handle->SetClearFlags(flags);
	}

	void Context::SetViewport(const Viewport &viewport) const
	{
		m_handle->SetViewport(viewport);
	}

	void Context::SetVsync(const bool vsync) const
	{
		m_handle->SetVsync(vsync);
	}

	void Context::SetWindow(const std::shared_ptr<Window> &window)
	{
		m_window = window;
		m_window->GetHandle()->SetGraphicsContext(m_handle);
		m_handle->SetWindow(m_window->GetHandle());
	}

	void Context::SetConfig(const ContextConfig &config) const
	{
		m_handle->SetConfig(config);
	}
}

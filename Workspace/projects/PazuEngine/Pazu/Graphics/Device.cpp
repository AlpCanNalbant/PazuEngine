#include "Shader/VertexShader.h"
#include "Shader/PixelShader.h"
#include "Buffer/VertexBuffer.h"
#include "Buffer/IndexBuffer.h"
#include "Buffer/ConstantBuffer.h"
#include "InputLayout/VertexInputLayout.h"
#include "SamplerState/SamplerState.h"
#include "Texture/Texture2D.h"
#include "BlendState/BlendState.h"
#include "Handle/Direct3D11/DeviceHandle.h"
#include "Device.h"

namespace Pazu::Graphics
{
	Device::Device()
	{
		switch (Engine::GetGraphicsApi())
		{
		case Api::Direct3D11:
			m_handle = std::make_shared<Direct3D11::DeviceHandle>();
			break;
		case Api::OpenGL:
			break;
		default:
			break;
		}
	}

	void Device::CreateShader(VertexShader &vertexShader) const
	{
		if (vertexShader.GetHandle())
			return Log::Get().Print<LogMode::Info>("VertexShader olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateShader(vertexShader);
	}

	void Device::CreateShader(PixelShader &pixelShader) const
	{
		if (pixelShader.GetHandle())
			return Log::Get().Print<LogMode::Info>("PixelShader olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateShader(pixelShader);
	}

	void Device::CreateBuffer(VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const
	{
		if (vertexBuffer.GetHandle())
			return Log::Get().Print<LogMode::Info>("VertexBuffer olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateBuffer(vertexBuffer);
	}

	void Device::CreateBuffer(VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const
	{
		if (vertexBuffer.GetHandle())
			return Log::Get().Print<LogMode::Info>("VertexBuffer olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateBuffer(vertexBuffer);
	}

	void Device::CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const
	{
		if (indexBuffer.GetHandle())
			return Log::Get().Print<LogMode::Info>("IndexBuffer olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateBuffer(indexBuffer);
	}

	void Device::CreateBuffer(ConstantBuffer &constantBuffer) const
	{
		if (constantBuffer.GetHandle())
			return Log::Get().Print<LogMode::Info>("ConstantBuffer olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateBuffer(constantBuffer);
	}

	void Device::CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &vertexInputLayout) const
	{
		if (vertexInputLayout.GetHandle())
			return Log::Get().Print<LogMode::Info>("VertexInputLayout olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateInputLayout(vertexShader, vertexInputLayout);
	}

	void Device::CreateSamplerState(SamplerState &samplerState) const
	{
		if (samplerState.GetHandle())
			return Log::Get().Print<LogMode::Info>("SamplerState olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateSamplerState(samplerState);
	}

	void Device::CreateTexture(Texture2D &texture2d) const
	{
		if (texture2d.GetHandle())
			return Log::Get().Print<LogMode::Info>("Texture2D olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateTexture(texture2d);
	}

	void Device::CreateBlendState(BlendState &blendState) const
	{
		if (blendState.GetHandle())
			return Log::Get().Print<LogMode::Info>("BlendState olusturulamadi. Zaten olusturulmus.");
		m_handle->CreateBlendState(blendState);
	}
}

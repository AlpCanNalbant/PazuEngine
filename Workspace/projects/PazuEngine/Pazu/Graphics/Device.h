#pragma once

namespace Pazu::Graphics
{
	class IDeviceHandle;
	class VertexShader;
	class PixelShader;
	struct VertexPositionNormalColorTexture;
	struct VertexPositionNormalColorTextureSkinning;
	template <typename T>
	class VertexBuffer;
	template <typename T>
	class IndexBuffer;
	class ConstantBuffer;
	class VertexInputLayout;
	class SamplerState;
	class Texture2D;
	class BlendState;
	class Device : public INonCopyable
	{
	public:
		Device();
		void CreateShader(VertexShader &vertexShader) const;
		void CreateShader(PixelShader &pixelShader) const;
		void CreateBuffer(VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const;
		void CreateBuffer(VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const;
		void CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const;
		void CreateBuffer(ConstantBuffer &constantBuffer) const;
		void CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &vertexInputLayout) const;
		void CreateSamplerState(SamplerState &samplerState) const;
		void CreateTexture(Texture2D &texture2d) const;
		void CreateBlendState(BlendState &blendState) const;
		template <typename T = IDeviceHandle>
		std::shared_ptr<T> GetHandle() const;

	private:
		std::shared_ptr<IDeviceHandle> m_handle;
	};
}
#include "Device.inl"

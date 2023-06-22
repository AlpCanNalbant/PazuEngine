#pragma once

namespace Pazu::Graphics
{
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
	class IDeviceHandle : public INonCopyable
	{
	public:
		virtual void CreateShader(VertexShader &vertexShader) const = 0;
		virtual void CreateShader(PixelShader &pixelShader) const = 0;
		virtual void CreateBuffer(VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const = 0;
		virtual void CreateBuffer(VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const = 0;
		virtual void CreateBuffer(IndexBuffer<unsigned int> &indexBuffer) const = 0;
		virtual void CreateBuffer(ConstantBuffer &constantBuffer) const = 0;
		virtual void CreateInputLayout(const VertexShader &vertexShader, VertexInputLayout &vertexInputLayout) const = 0;
		virtual void CreateSamplerState(SamplerState &samplerState) const = 0;
		virtual void CreateTexture(Texture2D &texture2d) const = 0;
		virtual void CreateBlendState(BlendState &blendState) const = 0;
	};
}

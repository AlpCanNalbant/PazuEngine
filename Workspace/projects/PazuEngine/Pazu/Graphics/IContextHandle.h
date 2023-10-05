// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../Math/Viewport.h"
#include "DrawMode.h"
#include "ClearFlag.h"

namespace Pazu
{
	class WindowHandle;
	struct Color;
}
namespace Pazu::Graphics
{
	struct ContextConfig;
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
	class IContextHandle : public INonCopyable
	{
	public:
		virtual void Resize(const Size &size) = 0;
		virtual void Clear() const = 0;
		virtual void Draw(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const = 0;
		virtual void Draw(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const = 0;
		virtual void Draw(const IndexBuffer<unsigned int> &indexBuffer) const = 0;
		virtual void Present() const = 0;
		virtual DrawMode GetDrawMode() const = 0;
		virtual bool GetCullFace() const = 0;
		virtual bool GetWireframe() const = 0;
		virtual const Color &GetClearColor() const = 0;
		virtual ClearFlag GetClearFlags() const = 0;
		virtual Size GetDrawableSize() const = 0;
		virtual Viewport GetViewport() const = 0;
		virtual bool GetVsync() const = 0;
		virtual bool GetFullscreen() const = 0;
		virtual const ContextConfig &GetConfig() const = 0;
		virtual void SetShader(const VertexShader &vertexShader) const = 0;
		virtual void SetShader(const PixelShader &pixelShader) const = 0;
		virtual void SetBuffer(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const = 0;
		virtual void SetBuffer(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const = 0;
		virtual void SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const = 0;
		virtual void SetBuffer(const ConstantBuffer &constantBuffer) const = 0;
		virtual void UpdateBuffer(const ConstantBuffer &constantBuffer) const = 0;
		virtual void SetInputLayout(const VertexInputLayout &layout) const = 0;
		virtual void SetSamplerState(const SamplerState &samplerState) const = 0;
		virtual void SetTexture(const Texture2D &texture2d) const = 0;
		virtual void SetBlendState(const BlendState &blendState) const = 0;
		virtual void SetDrawMode(const DrawMode drawMode) = 0;
		virtual void SetCullFace(const bool cullFace) = 0;
		virtual void SetWireframe(const bool wireframe) = 0;
		virtual void SetClearColor(const Color &color) = 0;
		virtual void SetClearFlags(const ClearFlag flags) = 0;
		virtual void SetViewport(const Viewport &viewport) const = 0;
		virtual void SetVsync(const bool vsync) = 0;
		virtual void SetFullscreen(const bool fullscreen) = 0;
		virtual void SetWindow(const std::shared_ptr<WindowHandle> &window) = 0;
		virtual void SetConfig(const ContextConfig &config) = 0;
	};
}

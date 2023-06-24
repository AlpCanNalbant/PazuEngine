#pragma once
#include "../Math/Viewport.h"
#include "DrawMode.h"
#include "ClearFlag.h"
#include "ContextConfig.h"

namespace Pazu
{
	class Window;
	struct Color;
}
namespace Pazu::Graphics
{
	class IContextHandle;
	class Device;
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
	class Context : public INonCopyable
	{
	public:
		Context(const std::shared_ptr<Device> &device, const std::shared_ptr<Window> &window, const ContextConfig &config = {});
		void Resize(const Size &size) const;
		void Clear() const;
		void Draw(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const;
		void Draw(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const;
		void Draw(const IndexBuffer<unsigned int> &indexBuffer) const;
		void Present() const;
		DrawMode GetDrawMode() const;
		bool GetCullFace() const;
		bool GetWireframe() const;
		const Color &GetClearColor() const;
		ClearFlag GetClearFlags() const;
		Size GetDrawableSize() const;
		Viewport GetViewport() const;
		bool GetVsync() const;
		const std::shared_ptr<Window> &GetWindow() const;
		const ContextConfig &GetConfig() const;
		template <typename T = IContextHandle>
		std::shared_ptr<T> GetHandle() const;
		void SetShader(const VertexShader &vertexShader) const;
		void SetShader(const PixelShader &pixelShader) const;
		void SetBuffer(const VertexBuffer<VertexPositionNormalColorTexture> &vertexBuffer) const;
		void SetBuffer(const VertexBuffer<VertexPositionNormalColorTextureSkinning> &vertexBuffer) const;
		void SetBuffer(const IndexBuffer<unsigned int> &indexBuffer) const;
		void SetBuffer(const ConstantBuffer &constantBuffer) const;
		void UpdateBuffer(const ConstantBuffer &constantBuffer) const;
		void SetInputLayout(const VertexInputLayout &layout) const;
		void SetSamplerState(const SamplerState &samplerState) const;
		void SetTexture(const Texture2D &texture2d) const;
		void SetBlendState(const BlendState &blendState) const;
		void SetDrawMode(const DrawMode drawMode) const;
		void SetCullFace(const bool cullFace) const;
		void SetWireframe(const bool wireframe) const;
		void SetClearColor(const Color &color) const;
		void SetClearFlags(const ClearFlag flags) const;
		void SetViewport(const Viewport &viewport) const;
		void SetVsync(const bool vsync) const;
		void SetWindow(const std::shared_ptr<Window> &window);
		void SetConfig(const ContextConfig &config) const;

	private:
		std::shared_ptr<IContextHandle> m_handle;
		std::shared_ptr<Device> m_device;
		std::shared_ptr<Window> m_window;
		ContextConfig m_config;
	};
}
#include "Context.inl"

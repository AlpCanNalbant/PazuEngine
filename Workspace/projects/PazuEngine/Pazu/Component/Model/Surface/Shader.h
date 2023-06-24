#pragma once
#include <typeindex>
#include "../../../Asset/ShaderAsset.h"

namespace Pazu::Graphics
{
	class VertexInputLayout;
	class ConstantBuffer;
}
namespace Pazu
{
	struct ShaderAsset;
	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::shared_ptr<ShaderAsset> &asset);
		void AddConstantBuffer(std::unique_ptr<Graphics::ConstantBuffer> constantBuffer);
		void AddConstantBuffers(std::vector<std::unique_ptr<Graphics::ConstantBuffer>> constantBuffers);
		template <typename T>
		const T *Get() const;
		const Graphics::VertexInputLayout &GetVertexInputLayout() const;
		const std::vector<std::unique_ptr<Graphics::ConstantBuffer>> &GetConstantBuffers() const;
		void SetConstantBuffers(std::vector<std::unique_ptr<Graphics::ConstantBuffer>> constantBuffers);
		void SetAsset(const std::shared_ptr<ShaderAsset> &asset);

	private:
		std::shared_ptr<ShaderAsset> m_asset;
	};
}
#include "Shader.inl"

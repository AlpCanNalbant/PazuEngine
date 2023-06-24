#pragma once
#include "../Graphics/Shader/Shader.h"
#include "../Graphics/InputLayout/VertexInputLayout.h"
#include "../Graphics/Buffer/ConstantBuffer.h"
#include "IAsset.h"

namespace Pazu
{
	struct ShaderAsset : public IAsset
	{
		ShaderAsset() = default;
		ShaderAsset(std::unordered_map<std::type_index, std::unique_ptr<Graphics::Shader>> stages);
		ShaderAsset(std::unordered_map<std::type_index, std::unique_ptr<Graphics::Shader>> stages, Graphics::VertexInputLayout vertexInputLayout, std::vector<std::unique_ptr<Graphics::ConstantBuffer>> constantBuffers);

		std::unordered_map<std::type_index, std::unique_ptr<Graphics::Shader>> stages;
		Graphics::VertexInputLayout vertexInputLayout;
		std::vector<std::unique_ptr<Graphics::ConstantBuffer>> constantBuffers;
	};
} // namespace Pazu

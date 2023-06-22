#include "ShaderAsset.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	ShaderAsset::ShaderAsset(std::unordered_map<std::type_index, std::unique_ptr<Graphics::Shader>> stages)
			: stages(std::move(stages)) {}

	ShaderAsset::ShaderAsset(std::unordered_map<std::type_index, std::unique_ptr<Graphics::Shader>> stages, Graphics::VertexInputLayout vertexInputLayout, std::vector<std::unique_ptr<Graphics::ConstantBuffer>> constantBuffers)
			: stages(std::move(stages)), vertexInputLayout(std::move(vertexInputLayout)), constantBuffers(std::move(constantBuffers)) {}
} // namespace Pazu

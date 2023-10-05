// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Shader.h"
using namespace Pazu::Graphics;

namespace Pazu
{
	Shader::Shader(const std::shared_ptr<ShaderAsset> &asset)
		: m_asset(asset) {}

	void Shader::AddConstantBuffer(std::unique_ptr<ConstantBuffer> constantBuffer)
	{
		m_asset->constantBuffers.emplace_back(std::move(constantBuffer));
	}

	void Shader::AddConstantBuffers(std::vector<std::unique_ptr<ConstantBuffer>> constantBuffers)
	{
		for (auto &constantBuffer : constantBuffers)
			AddConstantBuffer(std::move(constantBuffer));
	}

	const VertexInputLayout &Shader::GetVertexInputLayout() const
	{
		return m_asset->vertexInputLayout;
	}

	const std::vector<std::unique_ptr<ConstantBuffer>> &Shader::GetConstantBuffers() const
	{
		return m_asset->constantBuffers;
	}

	void Shader::SetConstantBuffers(std::vector<std::unique_ptr<ConstantBuffer>> constantBuffers)
	{
		m_asset->constantBuffers = std::move(constantBuffers);
	}

	void Shader::SetAsset(const std::shared_ptr<ShaderAsset> &asset)
	{
		m_asset = asset;
	}
}

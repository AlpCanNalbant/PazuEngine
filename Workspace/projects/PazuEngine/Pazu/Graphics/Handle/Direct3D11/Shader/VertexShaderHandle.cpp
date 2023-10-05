// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "VertexShaderHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	VertexShaderHandle::VertexShaderHandle(VertexShader &vertexShader)
		: ShaderHandle(vertexShader, "vs_5_0") {}

	const UniqueComPtr<ID3D11VertexShader> &VertexShaderHandle::Get() const
	{
		return m_shader;
	}

	void VertexShaderHandle::Set(UniqueComPtr<ID3D11VertexShader> shader)
	{
		m_shader = std::move(shader);
	}
}

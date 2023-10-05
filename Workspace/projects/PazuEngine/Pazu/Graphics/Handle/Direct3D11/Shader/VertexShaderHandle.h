// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Shader/VertexShader.h"
#include "ShaderHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class VertexShaderHandle : public ShaderHandle
	{
	public:
		VertexShaderHandle(VertexShader &vertexShader);
		const UniqueComPtr<ID3D11VertexShader> &Get() const;
		void Set(UniqueComPtr<ID3D11VertexShader> shader);

	private:
		UniqueComPtr<ID3D11VertexShader> m_shader;
	};
} // namespace Pazu::Direct3D11

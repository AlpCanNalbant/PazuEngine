// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "VertexInputLayoutHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	VertexInputLayoutHandle::VertexInputLayoutHandle(const VertexInputLayout &vertexInputLayout)
	{
		for (const auto &element : vertexInputLayout.GetElements())
		{
			switch (element.input)
			{
			case VertexInput::Position:
				m_elements.emplace_back("POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, element.byteOffset, D3D11_INPUT_PER_VERTEX_DATA, 0);
				break;
			case VertexInput::Normal:
				m_elements.emplace_back("NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, element.byteOffset, D3D11_INPUT_PER_VERTEX_DATA, 0);
				break;
			case VertexInput::Color:
				m_elements.emplace_back("COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, element.byteOffset, D3D11_INPUT_PER_VERTEX_DATA, 0);
				break;
			case VertexInput::Texture:
				m_elements.emplace_back("TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, element.byteOffset, D3D11_INPUT_PER_VERTEX_DATA, 0);
				break;
			case VertexInput::BlendIndices:
				m_elements.emplace_back("BLENDINDICES", 0, DXGI_FORMAT_R32G32B32A32_UINT, 0, element.byteOffset, D3D11_INPUT_PER_VERTEX_DATA, 0);
				break;
			case VertexInput::BlendWeights:
				m_elements.emplace_back("BLENDWEIGHTS", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, element.byteOffset, D3D11_INPUT_PER_VERTEX_DATA, 0);
				break;
			default:
				break;
			}
		}
	}
}

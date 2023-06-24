#include "VertexInputLayout.h"

namespace Pazu::Graphics
{
	void VertexInputLayout::Add(const VertexInput input)
	{
		switch (input)
		{
		case VertexInput::Position:
			m_elements.emplace_back(input, m_byteOffset);
			m_byteOffset += 3 * sizeof(float);
			return;
		case VertexInput::Normal:
			m_elements.emplace_back(input, m_byteOffset);
			m_byteOffset += 3 * sizeof(float);
			return;
		case VertexInput::Color:
			m_elements.emplace_back(input, m_byteOffset);
			m_byteOffset += 4 * sizeof(float);
			return;
		case VertexInput::Texture:
			m_elements.emplace_back(input, m_byteOffset);
			m_byteOffset += 2 * sizeof(float);
			return;
		case VertexInput::BlendIndices:
			m_elements.emplace_back(input, m_byteOffset);
			m_byteOffset += 4 * sizeof(unsigned int);
			return;
		case VertexInput::BlendWeights:
			m_elements.emplace_back(input, m_byteOffset);
			m_byteOffset += 4 * sizeof(float);
			return;
		default:
			return;
		}
	}
}

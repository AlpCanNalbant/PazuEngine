#pragma once
#include "VertexInput.h"
#include "InputLayout.h"

namespace Pazu::Graphics
{
	class VertexInputLayout : public InputLayout<VertexInput>
	{
	public:
		void Add(const VertexInput input);

	private:
		unsigned int m_byteOffset{0};
	};
} // namespace Pazu

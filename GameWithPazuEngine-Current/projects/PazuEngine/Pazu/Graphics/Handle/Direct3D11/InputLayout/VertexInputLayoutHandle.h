#pragma once
#include "InputLayoutHandle.h"
#include "../../../InputLayout/VertexInputLayout.h"

namespace Pazu::Graphics::Direct3D11
{
	class VertexInputLayoutHandle : public InputLayoutHandle
	{
	public:
		VertexInputLayoutHandle(const VertexInputLayout &vertexInputLayout);
	};
}

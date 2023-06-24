#pragma once
#include "../../../Shader/Shader.h"
#include "../../../IObjectHandle.h"

namespace Pazu::Graphics::Direct3D11
{
	class ShaderHandle : public IObjectHandle
	{
	public:
		ShaderHandle(Shader &shader, const std::string &target);
		const void *GetByteCode() const;
		std::size_t GetByteCodeSize() const;

	protected:
		UniqueComPtr<ID3DBlob> m_blob;
		std::string m_byteCode;
	};
} // namespace Pazu::Direct3D11

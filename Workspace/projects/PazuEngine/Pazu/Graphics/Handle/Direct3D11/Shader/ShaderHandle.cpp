// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include <d3dcompiler.h>
#include "ShaderHandle.h"
using namespace magic_enum;

namespace Pazu::Graphics::Direct3D11
{
	ShaderHandle::ShaderHandle(Shader &shader, const std::string &target)
	{
		if (!shader.GetCompiled())
		{
			UniqueComPtr<ID3DBlob> errorBlob;
			const auto &source = shader.GetSource();
			UINT shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(_DEBUG)
			shaderFlags |= D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif
			if (HRESULT hResult; SUCCEEDED(hResult = D3DCompile(source.c_str(), source.size(), nullptr, nullptr, nullptr, "main", target.c_str(), shaderFlags, 0, &m_blob, &errorBlob)))
				shader.SetCompiled(true);
			else
				WLog::Get().Print<LogMode::Error>(Log::Get().ToWide(target) + L" shader derlenemedi. " + Log::Get().ToString(hResult) + L" D3DCompile hata mesaji: " + static_cast<const wchar_t *>(errorBlob->GetBufferPointer()));
		}
		else
			m_byteCode = shader.GetSource();
	}

	const void *ShaderHandle::GetByteCode() const
	{
		if (m_byteCode.empty())
			return m_blob->GetBufferPointer();
		else
			return static_cast<const void *>(m_byteCode.data());
	}

	std::size_t ShaderHandle::GetByteCodeSize() const
	{
		if (m_byteCode.empty())
			return m_blob->GetBufferSize();
		else
			return m_byteCode.size();
	}
} // namespace Pazu

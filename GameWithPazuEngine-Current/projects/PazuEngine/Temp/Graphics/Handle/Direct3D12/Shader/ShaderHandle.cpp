#include <d3dcompiler.h>
#include "ShaderHandle.h"
using namespace Microsoft::WRL;
using namespace magic_enum;

namespace Pazu::Direct3D12
{
	ShaderHandle::ShaderHandle(ID3D12Device &device, Shader &shader, const std::string &target) noexcept
	{
		{
			CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
			rootSignatureDesc.Init(0, nullptr);
			ComPtr<ID3DBlob> signatureBlob;
			ComPtr<ID3DBlob> errorBlob;
			if (HRESULT hResult; hResult = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signatureBlob, &errorBlob))
				Log::Get().Print<LogMode::Fatal>("RootSignature serialize edilemedi. HRESULT hata kodu: " + Log::Get().ToHexString(static_cast<unsigned int>(hResult)) + " D3D hata mesaji: " + static_cast<const char *>(errorBlob->GetBufferPointer()));
			if (HRESULT hResult; hResult = device.CreateRootSignature(0, signatureBlob->GetBufferPointer(), signatureBlob->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature)))
				Log::Get().Print<LogMode::Fatal>("RootSignature olusturulamadi. HRESULT hata kodu: " + Log::Get().ToHexString(static_cast<unsigned int>(hResult)));
		}
		ComPtr<ID3DBlob> shaderBlob;
		std::string compiledByteCode;
		if (!shader.GetCompiled())
		{
			ComPtr<ID3DBlob> errorBlob;
			const auto &source = shader.GetSource();
			UINT shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(_DEBUG)
			shaderFlags |= D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif
			if (HRESULT hResult; SUCCEEDED(hResult = D3DCompile(source.c_str(), source.size(), nullptr, nullptr, nullptr, "main", target.c_str(), shaderFlags, 0, &shaderBlob, &errorBlob)))
				shader.SetCompiled(true);
			else
				Log::Get().Print<LogMode::Error>(target + " shader derlenemedi. HRESULT hata kodu: " + Log::Get().ToHexString(static_cast<unsigned int>(hResult)) + " D3DCompile hata mesaji: " + static_cast<const char *>(errorBlob->GetBufferPointer()));
		}
		else
			compiledByteCode = shader.GetSource();
		D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineStateDesc = {};
		pipelineStateDesc.pRootSignature = m_rootSignature.Get();
	}

	// const void *ShaderHandle::GetByteCode() const noexcept
	// {
	// 	if (m_byteCode.empty())
	// 		return m_blob->GetBufferPointer();
	// 	else
	// 		return static_cast<const void *>(m_byteCode.data());
	// }

	// std::size_t ShaderHandle::GetByteCodeSize() const noexcept
	// {
	// 	if (m_byteCode.empty())
	// 		return m_blob->GetBufferSize();
	// 	else
	// 		return m_byteCode.size();
	// }
} // namespace Pazu

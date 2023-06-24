#pragma once
#include "../../../Shader/Shader.h"
#include "../../../IGraphicsObjectHandle.h"

namespace Pazu::Direct3D12
{
	class ShaderHandle : public IGraphicsObjectHandle
	{
	public:
		ShaderHandle(ID3D12Device &device, Shader &shader, const std::string &target) noexcept;

	protected:
		// Microsoft::WRL::ComPtr<ID3DBlob> m_blob;
		Microsoft::WRL::ComPtr<ID3D12RootSignature> m_rootSignature;
		Microsoft::WRL::ComPtr<ID3D12PipelineState> m_pipelineState;
		// CD3DX12_ROOT_SIGNATURE_DESC m_rootSignatureDesc{};
		// D3D12_GRAPHICS_PIPELINE_STATE_DESC m_pipelineStateDesc{};
		// D3D12_SHADER_BYTECODE m_d3dByteCode;
		// std::string m_byteCode;
	};
} // namespace Pazu::Direct3D12

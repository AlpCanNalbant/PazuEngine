#pragma pack_matrix(row_major)

struct VsInput
{
	float3 Position : POSITION0;
	float3 Normal : NORMAL0;
	float4 Color : COLOR0;
	float2 TexCoord : TEXCOORD0;
	uint4 BlendIndices : BLENDINDICES0;
	float4 BlendWeights : BLENDWEIGHTS0;
};

struct VsOutput
{
	float4 Position : SV_POSITION;
	float3 Normal : NORMAL0;
	float4 Color : COLOR0;
	float2 TexCoord : TEXCOORD0;
};

cbuffer Camera : register(b0)
{
	matrix Projection;
};

cbuffer CameraTransform : register(b1)
{
	matrix View;
};

cbuffer ObjectTransform : register(b2)
{
  matrix World;
};

cbuffer Skinned : register(b3)
{
	matrix BoneTransforms[96];
};

VsOutput VS(VsInput input)
{
	VsOutput output = (VsOutput)0;

	// matrix transform = mul(BoneTransforms[input.BlendIndices[0]], input.BlendWeights[0]);
	// transform += mul(BoneTransforms[input.BlendIndices[1]], input.BlendWeights[1]);
	// transform += mul(BoneTransforms[input.BlendIndices[2]], input.BlendWeights[2]);
	// transform += mul(BoneTransforms[input.BlendIndices[3]], input.BlendWeights[3]);
	// float4 localPosition = mul(float4(input.Position, 1.f), transform);

	float4 totalPosition = {0.f, 0.f, 0.f, 0.f};
	for (int i = 0; i < 4; i++)
		totalPosition += input.BlendWeights[i] * mul(float4(input.Position, 1.f), BoneTransforms[input.BlendIndices[i]]);

	matrix wvp = mul(World, mul(View, Projection));
	output.Position = mul(totalPosition, wvp);
	output.Normal = input.Normal;
	output.Color = input.Color;
	output.TexCoord = input.TexCoord;

	return output;
}

SamplerState g_samplerState;
Texture2D g_texture;

float4 PS(VsOutput input) : SV_TARGET
{
	return g_texture.Sample(g_samplerState, input.TexCoord);
	// return input.Color;
}

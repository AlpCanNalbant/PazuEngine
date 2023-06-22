#pragma pack_matrix(row_major)

struct VsOutput
{
	float4 Position : SV_POSITION;
	float3 Normal : NORMAL0;
	float4 Color : COLOR0;
	float2 TexCoord : TEXCOORD0;
};

cbuffer ObjectTransform : register(b2)
{
  matrix World;
};

cbuffer CameraTransform : register(b1)
{
	matrix View;
};

cbuffer Camera : register(b0)
{
	matrix Projection;
};

VsOutput VS(float3 inPosition : POSITION0, float3 inNormal : NORMAL0, float4 inColor : COLOR0, float2 inTexCoord : TEXCOORD0)
{
	VsOutput output = (VsOutput)0;
	matrix wvp = mul(World, mul(View, Projection));
	output.Position = mul(float4(inPosition, 1.f), wvp);
	output.Normal = inNormal;
	output.Color = inColor;
	output.TexCoord = inTexCoord;
	return output;
}

SamplerState g_samplerState;
Texture2D g_texture;

float4 PS(VsOutput input) : SV_TARGET
{
	return g_texture.Sample(g_samplerState, input.TexCoord);
}

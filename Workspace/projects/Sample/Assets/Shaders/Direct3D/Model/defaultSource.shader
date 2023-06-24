@Global
struct VsOutput
{
	float4 Position : SV_POSITION;
	float3 Normal : NORMAL0;
	float4 Color : COLOR0;
	float2 TexCoord : TEXCOORD0;
};

@Vertex
cbuffer ObjectTransform : register(b0)
{
	matrix World;
};

VsOutput main(float4 inPosition : POSITION0, float3 inNormal : NORMAL0, float4 inColor : COLOR0, float2 inTexCoord : TEXCOORD0)
{
	VsOutput output = (VsOutput)0;
	output.Position = mul(inPosition, World);
	output.Normal = inNormal;
	output.Color = inColor;
	output.TexCoord = inTexCoord;
	return output;
}

@Pixel
SamplerState g_samplerState;
Texture2D g_texture;

float4 main(VsOutput input) : SV_TARGET
{
	return g_texture.Sample(g_samplerState, input.TexCoord);
}

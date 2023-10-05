// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	constexpr VertexPositionColorTexture::VertexPositionColorTexture(const Vector3 &position, const Color &color, const Vector2 &texture)
		: position(position), color(color), texture(texture) {}
}

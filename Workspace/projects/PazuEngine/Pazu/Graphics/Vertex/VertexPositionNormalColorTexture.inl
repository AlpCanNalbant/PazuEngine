namespace Pazu::Graphics
{
	constexpr VertexPositionNormalColorTexture::VertexPositionNormalColorTexture(const Vector3 &position, const Vector3 &normal, const Color &color, const Vector2 &texture)
			: position(position), normal(normal), color(color), texture(texture) {}
}

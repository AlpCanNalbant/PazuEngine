// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu::Graphics
{
	constexpr VertexPositionNormalColorTextureSkinning::VertexPositionNormalColorTextureSkinning(const Vector3 &position, const Vector3 &normal, const Color &color, const Vector2 &texture, const std::array<unsigned int, 4> &indices, const std::array<float, 4> &weights)
		: position(position), normal(normal), color(color), texture(texture), indices(indices), weights(weights) {}
}

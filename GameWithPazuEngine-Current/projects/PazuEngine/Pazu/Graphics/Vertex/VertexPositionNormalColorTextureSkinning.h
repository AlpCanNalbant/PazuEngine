#pragma once
#include "../../Math/Color.h"
#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"
#include "../../Math/Vector4.h"

namespace Pazu::Graphics
{
	struct VertexPositionNormalColorTextureSkinning
	{
		VertexPositionNormalColorTextureSkinning() = default;
		constexpr VertexPositionNormalColorTextureSkinning(const Vector3 &position, const Vector3 &normal, const Color &color, const Vector2 &texture, const std::array<unsigned int, 4> &indices, const std::array<float, 4> &weights);

		Vector3 position;
		Vector3 normal;
		Color color;
		Vector2 texture;
		std::array<unsigned int, 4> indices{};
		std::array<float, 4> weights{};
	};
} // namespace Pazu
#include "VertexPositionNormalColorTextureSkinning.inl"

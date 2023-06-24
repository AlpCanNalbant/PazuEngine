#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"
#include "VertexTexture.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormalTexture : public VertexPosition<T>, public VertexNormal<T>, public VertexTexture<T>
	{
	public:
		VertexPositionNormalTexture() noexcept = default;
		VertexPositionNormalTexture(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData, const std::array<T, 2> &textureData) noexcept;
		VertexPositionNormalTexture(const Vector3 &position, const Vector3 &normal, const Vector2 &texture) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormalTexture.inl"

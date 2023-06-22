#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"
#include "VertexColor.h"
#include "VertexTexture.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormalColorTexture : public VertexPosition<T>, public VertexNormal<T>, public VertexColor<T>, public VertexTexture<T>
	{
	public:
		VertexPositionNormalColorTexture() noexcept = default;
		VertexPositionNormalColorTexture(const std::array<T, 3> &position, const std::array<T, 3> &normal, const std::array<T, 4> &color, const std::array<T, 2> &texture) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormalColorTexture.inl"

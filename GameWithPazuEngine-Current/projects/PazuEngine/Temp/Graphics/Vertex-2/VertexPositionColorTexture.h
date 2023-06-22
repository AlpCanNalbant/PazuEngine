#pragma once
#include "VertexPosition.h"
#include "VertexColor.h"
#include "VertexTexture.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionColorTexture : public VertexPosition<T>, public VertexColor<T>, public VertexTexture<T>
	{
	public:
		VertexPositionColorTexture() noexcept = default;
		VertexPositionColorTexture(const std::array<T, 3> &position, const std::array<T, 4> &color, const std::array<T, 2> &texture) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionColorTexture.inl"

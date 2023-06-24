#pragma once
#include "VertexPosition.h"
#include "VertexColor.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionColor : public VertexPosition<T>, public VertexColor<T>
	{
	public:
		VertexPositionColor() noexcept = default;
		VertexPositionColor(const std::array<T, 3> &positionData, const std::array<T, 4> &colorData) noexcept;
		VertexPositionColor(const Vector3 &position, const Color &color) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionColor.inl"

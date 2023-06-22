#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"
#include "VertexColor.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormalColor : public VertexPosition<T>, public VertexNormal<T>, public VertexColor<T>
	{
	public:
		VertexPositionNormalColor() noexcept = default;
		VertexPositionNormalColor(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData, const std::array<T, 4> &colorData) noexcept;
		VertexPositionNormalColor(const Vector3 &position, const Vector3 &normal, const Color &color) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormalColor.inl"

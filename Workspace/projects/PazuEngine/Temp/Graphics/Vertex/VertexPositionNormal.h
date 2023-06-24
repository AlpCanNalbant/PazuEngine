#pragma once
#include "VertexPosition.h"
#include "VertexNormal.h"

namespace Pazu
{
	template <typename T>
	class VertexPositionNormal : public VertexPosition<T>, public VertexNormal<T>
	{
	public:
		VertexPositionNormal() noexcept = default;
		VertexPositionNormal(const std::array<T, 3> &positionData, const std::array<T, 3> &normalData) noexcept;
		VertexPositionNormal(const Vector3 &position, const Vector3 &normal) noexcept;
		std::vector<T> ToData() const noexcept final;
		VertexFlag GetFlags() const noexcept final;
	};
} // namespace Pazu
#include "VertexPositionNormal.inl"

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Vector3.h"
#include "IVertex.h"

namespace Pazu
{
	template <typename T>
	class VertexPosition : public IVertex<T>
	{
	public:
		VertexPosition() noexcept = default;
		VertexPosition(const std::array<T, 3> &positionData) noexcept;
		VertexPosition(const Vector3 &position) noexcept;
		Vector3 GetPosition() const noexcept;
		void SetPosition(const Vector3 &position) noexcept;
		std::vector<T> ToData() const noexcept override;
		VertexFlag GetFlags() const noexcept override;

	protected:
		std::array<T, 3> m_positionData;
	};
} // namespace Pazu
#include "VertexPosition.inl"

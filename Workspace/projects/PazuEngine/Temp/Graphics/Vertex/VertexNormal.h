// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Vector3.h"

namespace Pazu
{
	template <typename T>
	class VertexNormal
	{
	public:
		VertexNormal() noexcept = default;
		VertexNormal(const std::array<T, 3> &normalData) noexcept;
		VertexNormal(const Vector3 &normal) noexcept;
		VertexNormal(const VertexNormal &other) noexcept = default;
		VertexNormal(VertexNormal &&temp) noexcept = default;
		virtual ~VertexNormal() noexcept = 0;
		VertexNormal &operator=(const VertexNormal &other) noexcept = default;
		VertexNormal &operator=(VertexNormal &&temp) noexcept = default;
		Vector3 GetNormal() const noexcept;
		void SetNormal(const Vector3 &normal) noexcept;

	protected:
		std::array<T, 3> m_normalData;
	};
} // namespace Pazu
#include "VertexNormal.inl"

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------

#pragma once
#include "Vector3.h"

namespace DirectX
{
	struct BoundingSphere;
	struct BoundingBox;
} // namespace DirectX

namespace Pazu::Math
{
	struct Plane;

	class Ray
	{
	public:
		Ray() noexcept;
		Ray(const Vector3 &pos, const Vector3 &dir) noexcept;
		Ray(const Ray &) = default;
		Ray &operator=(const Ray &) = default;
		Ray(Ray &&) = default;
		Ray &operator=(Ray &&) = default;
		bool operator==(const Ray &r) const noexcept;
		bool operator!=(const Ray &r) const noexcept;
		bool Intersects(const DirectX::BoundingSphere &sphere, _Out_ float &Dist) const noexcept;
		bool Intersects(const DirectX::BoundingBox &box, _Out_ float &Dist) const noexcept;
		bool Intersects(const Vector3 &tri0, const Vector3 &tri1, const Vector3 &tri2, _Out_ float &Dist) const noexcept;
		bool Intersects(const Plane &plane, _Out_ float &Dist) const noexcept;

		Vector3 position;
		Vector3 direction;
	};
} // namespace Pazu

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Ray>
	{
		bool operator()(const Pazu::Math::Ray &R1, const Pazu::Math::Ray &R2) const noexcept;
	};
} // namespace std

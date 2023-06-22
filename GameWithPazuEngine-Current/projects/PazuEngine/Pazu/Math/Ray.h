//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

namespace Pazu
{
	struct Plane;

	class Ray
	{
	public:
		Ray();
		Ray(const Vector3 &pos, const Vector3 &dir);
		Ray(const Ray &) = default;
		Ray &operator=(const Ray &) = default;
		Ray(Ray &&) = default;
		Ray &operator=(Ray &&) = default;
		bool operator==(const Ray &r) const;
		bool operator!=(const Ray &r) const;
		bool Intersects(const DirectX::BoundingSphere &sphere, _Out_ float &Dist) const;
		bool Intersects(const DirectX::BoundingBox &box, _Out_ float &Dist) const;
		bool Intersects(const Vector3 &tri0, const Vector3 &tri1, const Vector3 &tri2, _Out_ float &Dist) const;
		bool Intersects(const Plane &plane, _Out_ float &Dist) const;

		Vector3 position;
		Vector3 direction;
	};
} // namespace Pazu

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Ray>
	{
		bool operator()(const Pazu::Ray &R1, const Pazu::Ray &R2) const;
	};
} // namespace std

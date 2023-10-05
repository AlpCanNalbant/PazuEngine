// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

//-------------------------------------------------------------------------------------
// SimpleMath.inl -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------

#include <functional>
#include <XMath/DirectXCollision.h>
#include "Vector3.h"
#include "Plane.h"
#include "Ray.h"

namespace Pazu::Math
{
	Ray::Ray() noexcept
		: position(0.f, 0.f, 0.f), direction(0.f, 0.f, 1.f) {}

	Ray::Ray(const Vector3 &pos, const Vector3 &dir) noexcept
		: position(pos), direction(dir) {}

	bool Ray::operator==(const Ray &r) const noexcept
	{
		using namespace DirectX;
		XMVECTOR r1p = XMLoadFloat3(&position);
		XMVECTOR r2p = XMLoadFloat3(&r.position);
		XMVECTOR r1d = XMLoadFloat3(&direction);
		XMVECTOR r2d = XMLoadFloat3(&r.direction);
		return XMVector3Equal(r1p, r2p) && XMVector3Equal(r1d, r2d);
	}

	bool Ray::operator!=(const Ray &r) const noexcept
	{
		using namespace DirectX;
		XMVECTOR r1p = XMLoadFloat3(&position);
		XMVECTOR r2p = XMLoadFloat3(&r.position);
		XMVECTOR r1d = XMLoadFloat3(&direction);
		XMVECTOR r2d = XMLoadFloat3(&r.direction);
		return XMVector3NotEqual(r1p, r2p) && XMVector3NotEqual(r1d, r2d);
	}

	bool Ray::Intersects(const DirectX::BoundingSphere &sphere, _Out_ float &Dist) const noexcept
	{
		return sphere.Intersects(position, direction, Dist);
	}

	bool Ray::Intersects(const DirectX::BoundingBox &box, _Out_ float &Dist) const noexcept
	{
		return box.Intersects(position, direction, Dist);
	}

	bool Ray::Intersects(const Vector3 &tri0, const Vector3 &tri1, const Vector3 &tri2, _Out_ float &Dist) const noexcept
	{
		return DirectX::TriangleTests::Intersects(position, direction, tri0, tri1, tri2, Dist);
	}

	bool Ray::Intersects(const Plane &plane, _Out_ float &Dist) const noexcept
	{
		using namespace DirectX;

		XMVECTOR p = XMLoadFloat4(&plane);
		XMVECTOR dir = XMLoadFloat3(&direction);

		XMVECTOR nd = XMPlaneDotNormal(p, dir);

		if (XMVector3LessOrEqual(XMVectorAbs(nd), g_RayEpsilon))
		{
			Dist = 0.f;
			return false;
		}
		else
		{
			// t = -(dot(n,origin) + D) / dot(n,dir)
			XMVECTOR pos = XMLoadFloat3(&position);
			XMVECTOR v = XMPlaneDotNormal(p, pos);
			v = XMVectorAdd(v, XMVectorSplatW(p));
			v = XMVectorDivide(v, nd);
			float dist = -XMVectorGetX(v);
			if (dist < 0)
			{
				Dist = 0.f;
				return false;
			}
			else
			{
				Dist = dist;
				return true;
			}
		}
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Ray>::operator()(const Pazu::Math::Ray &R1, const Pazu::Math::Ray &R2) const noexcept
	{
		if (R1.position.x != R2.position.x)
			return R1.position.x < R2.position.x;
		if (R1.position.y != R2.position.y)
			return R1.position.y < R2.position.y;
		if (R1.position.z != R2.position.z)
			return R1.position.z < R2.position.z;

		if (R1.direction.x != R2.direction.x)
			return R1.direction.x < R2.direction.x;
		if (R1.direction.y != R2.direction.y)
			return R1.direction.y < R2.direction.y;
		if (R1.direction.z != R2.direction.z)
			return R1.direction.z < R2.direction.z;
		return false;
	}
} // namespace std

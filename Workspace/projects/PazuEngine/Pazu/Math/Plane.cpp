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
#include "Matrix.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Plane.h"

namespace Pazu
{
	Plane::Plane()
		: XMFLOAT4(0.f, 1.f, 0.f, 0.f) {}

	Plane::Plane(const Vector3 &normal, float d)
		: XMFLOAT4(normal.x, normal.y, normal.z, d) {}

	Plane::Plane(const Vector3 &point1, const Vector3 &point2, const Vector3 &point3)
	{
		using namespace DirectX;
		XMVECTOR P0 = XMLoadFloat3(&point1);
		XMVECTOR P1 = XMLoadFloat3(&point2);
		XMVECTOR P2 = XMLoadFloat3(&point3);
		XMStoreFloat4(this, XMPlaneFromPoints(P0, P1, P2));
	}

	Plane::Plane(const Vector3 &point, const Vector3 &normal)
	{
		using namespace DirectX;
		XMVECTOR P = XMLoadFloat3(&point);
		XMVECTOR N = XMLoadFloat3(&normal);
		XMStoreFloat4(this, XMPlaneFromPointNormal(P, N));
	}

	Plane::Plane(const Vector4 &v)
		: XMFLOAT4(v.x, v.y, v.z, v.w) {}

	Plane::Plane(_In_reads_(4) const float *pArray)
		: XMFLOAT4(pArray) {}

	Plane::Plane(DirectX::FXMVECTOR V)
	{
		XMStoreFloat4(this, V);
	}

	Plane::Plane(const XMFLOAT4 &p)
	{
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
		this->w = p.w;
	}

	Plane::Plane(const DirectX::XMVECTORF32 &F)
	{
		this->x = F.f[0];
		this->y = F.f[1];
		this->z = F.f[2];
		this->w = F.f[3];
	}

	Plane::operator DirectX::XMVECTOR() const
	{
		return XMLoadFloat4(this);
	}

	bool Plane::operator==(const Plane &p) const
	{
		using namespace DirectX;
		XMVECTOR p1 = XMLoadFloat4(this);
		XMVECTOR p2 = XMLoadFloat4(&p);
		return XMPlaneEqual(p1, p2);
	}

	bool Plane::operator!=(const Plane &p) const
	{
		using namespace DirectX;
		XMVECTOR p1 = XMLoadFloat4(this);
		XMVECTOR p2 = XMLoadFloat4(&p);
		return XMPlaneNotEqual(p1, p2);
	}

	Plane &Plane::operator=(const DirectX::XMVECTORF32 &F)
	{
		x = F.f[0];
		y = F.f[1];
		z = F.f[2];
		w = F.f[3];
		return *this;
	}

	Vector3 Plane::Normal() const
	{
		return Vector3(x, y, z);
	}

	void Plane::Normal(const Vector3 &normal)
	{
		x = normal.x;
		y = normal.y;
		z = normal.z;
	}

	float Plane::D() const
	{
		return w;
	}

	void Plane::D(float d)
	{
		w = d;
	}

	void Plane::Normalize()
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(this);
		XMStoreFloat4(this, XMPlaneNormalize(p));
	}

	void Plane::Normalize(Plane &result) const
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMPlaneNormalize(p));
	}

	float Plane::Dot(const Vector4 &v) const
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(this);
		XMVECTOR v0 = XMLoadFloat4(&v);
		return XMVectorGetX(XMPlaneDot(p, v0));
	}

	float Plane::DotCoordinate(const Vector3 &position) const
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(this);
		XMVECTOR v0 = XMLoadFloat3(&position);
		return XMVectorGetX(XMPlaneDotCoord(p, v0));
	}

	float Plane::DotNormal(const Vector3 &normal) const
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(this);
		XMVECTOR n0 = XMLoadFloat3(&normal);
		return XMVectorGetX(XMPlaneDotNormal(p, n0));
	}

	void Plane::Transform(const Plane &plane, const Matrix &M, Plane &result)
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(&plane);
		XMMATRIX m0 = XMLoadFloat4x4(&M);
		XMStoreFloat4(&result, XMPlaneTransform(p, m0));
	}

	Plane Plane::Transform(const Plane &plane, const Matrix &M)
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(&plane);
		XMMATRIX m0 = XMLoadFloat4x4(&M);

		Plane result;
		XMStoreFloat4(&result, XMPlaneTransform(p, m0));
		return result;
	}

	void Plane::Transform(const Plane &plane, const Quaternion &rotation, Plane &result)
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(&plane);
		XMVECTOR q = XMLoadFloat4(&rotation);
		XMVECTOR X = XMVector3Rotate(p, q);
		X = XMVectorSelect(p, X, g_XMSelect1110); // result.d = plane.d
		XMStoreFloat4(&result, X);
	}

	Plane Plane::Transform(const Plane &plane, const Quaternion &rotation)
	{
		using namespace DirectX;
		XMVECTOR p = XMLoadFloat4(&plane);
		XMVECTOR q = XMLoadFloat4(&rotation);
		XMVECTOR X = XMVector3Rotate(p, q);
		X = XMVectorSelect(p, X, g_XMSelect1110); // result.d = plane.d

		Plane result;
		XMStoreFloat4(&result, X);
		return result;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Plane>::operator()(const Pazu::Plane &P1, const Pazu::Plane &P2) const
	{
		return ((P1.x < P2.x) || ((P1.x == P2.x) && (P1.y < P2.y)) || ((P1.x == P2.x) && (P1.y == P2.y) && (P1.z < P2.z)) || ((P1.x == P2.x) && (P1.y == P2.y) && (P1.z == P2.z) && (P1.w < P2.w)));
	}
} // namespace std

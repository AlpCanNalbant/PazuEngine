//-------------------------------------------------------------------------------------
// SimpleMath.inl -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
#include <functional>
#include "Matrix.h"
#include "Quaternion.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Pazu::Math
{
	Vector4::Vector4() noexcept
			: XMFLOAT4(0.f, 0.f, 0.f, 0.f) {}

	Vector4::Vector4(_In_reads_(4) const float *pArray) noexcept
			: XMFLOAT4(pArray) {}

	Vector4::Vector4(DirectX::FXMVECTOR V) noexcept
	{
		XMStoreFloat4(this, V);
	}

	Vector4::Vector4(const XMFLOAT4 &V) noexcept
	{
		this->x = V.x;
		this->y = V.y;
		this->z = V.z;
		this->w = V.w;
	}

	Vector4::Vector4(const DirectX::XMVECTORF32 &F) noexcept
	{
		this->x = F.f[0];
		this->y = F.f[1];
		this->z = F.f[2];
		this->w = F.f[3];
	}

	Vector4::operator DirectX::XMVECTOR() const noexcept
	{
		return XMLoadFloat4(this);
	}

	bool Vector4::operator==(const Vector4 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&V);
		return XMVector4Equal(v1, v2);
	}

	bool Vector4::operator!=(const Vector4 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&V);
		return XMVector4NotEqual(v1, v2);
	}

	Vector4 &Vector4::operator=(const DirectX::XMVECTORF32 &F) noexcept
	{
		x = F.f[0];
		y = F.f[1];
		z = F.f[2];
		w = F.f[3];
		return *this;
	}

	Vector4 &Vector4::operator+=(const Vector4 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&V);
		XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreFloat4(this, X);
		return *this;
	}

	Vector4 &Vector4::operator-=(const Vector4 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&V);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreFloat4(this, X);
		return *this;
	}

	Vector4 &Vector4::operator*=(const Vector4 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&V);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreFloat4(this, X);
		return *this;
	}

	Vector4 &Vector4::operator*=(float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVectorScale(v1, S);
		XMStoreFloat4(this, X);
		return *this;
	}

	Vector4 &Vector4::operator/=(float S) noexcept
	{
		using namespace DirectX;
		assert(S != 0.0f);
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVectorScale(v1, 1.f / S);
		XMStoreFloat4(this, X);
		return *this;
	}

	Vector4 Vector4::operator+() const noexcept
	{
		return *this;
	}

	Vector4 Vector4::operator-() const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVectorNegate(v1);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	bool Vector4::InBounds(const Vector4 &Bounds) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&Bounds);
		return XMVector4InBounds(v1, v2);
	}

	float Vector4::Length() const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVector4Length(v1);
		return XMVectorGetX(X);
	}

	float Vector4::LengthSquared() const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVector4LengthSq(v1);
		return XMVectorGetX(X);
	}

	float Vector4::Dot(const Vector4 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&V);
		XMVECTOR X = XMVector4Dot(v1, v2);
		return XMVectorGetX(X);
	}

	void Vector4::Cross(const Vector4 &v1, const Vector4 &v2, Vector4 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(this);
		XMVECTOR x2 = XMLoadFloat4(&v1);
		XMVECTOR x3 = XMLoadFloat4(&v2);
		XMVECTOR R = XMVector4Cross(x1, x2, x3);
		XMStoreFloat4(&result, R);
	}

	Vector4 Vector4::Cross(const Vector4 &v1, const Vector4 &v2) const noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(this);
		XMVECTOR x2 = XMLoadFloat4(&v1);
		XMVECTOR x3 = XMLoadFloat4(&v2);
		XMVECTOR R = XMVector4Cross(x1, x2, x3);

		Vector4 result;
		XMStoreFloat4(&result, R);
		return result;
	}

	void Vector4::Normalize() noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVector4Normalize(v1);
		XMStoreFloat4(this, X);
	}

	void Vector4::Normalize(Vector4 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR X = XMVector4Normalize(v1);
		XMStoreFloat4(&result, X);
	}

	void Vector4::Clamp(const Vector4 &vmin, const Vector4 &vmax) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&vmin);
		XMVECTOR v3 = XMLoadFloat4(&vmax);
		XMVECTOR X = XMVectorClamp(v1, v2, v3);
		XMStoreFloat4(this, X);
	}

	void Vector4::Clamp(const Vector4 &vmin, const Vector4 &vmax, Vector4 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(this);
		XMVECTOR v2 = XMLoadFloat4(&vmin);
		XMVECTOR v3 = XMLoadFloat4(&vmax);
		XMVECTOR X = XMVectorClamp(v1, v2, v3);
		XMStoreFloat4(&result, X);
	}

	float Vector4::Distance(const Vector4 &v1, const Vector4 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR V = XMVectorSubtract(x2, x1);
		XMVECTOR X = XMVector4Length(V);
		return XMVectorGetX(X);
	}

	float Vector4::DistanceSquared(const Vector4 &v1, const Vector4 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR V = XMVectorSubtract(x2, x1);
		XMVECTOR X = XMVector4LengthSq(V);
		return XMVectorGetX(X);
	}

	void Vector4::Min(const Vector4 &v1, const Vector4 &v2, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorMin(x1, x2);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Min(const Vector4 &v1, const Vector4 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorMin(x1, x2);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Max(const Vector4 &v1, const Vector4 &v2, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorMax(x1, x2);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Max(const Vector4 &v1, const Vector4 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorMax(x1, x2);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Lerp(const Vector4 &v1, const Vector4 &v2, float t, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Lerp(const Vector4 &v1, const Vector4 &v2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::SmoothStep(const Vector4 &v1, const Vector4 &v2, float t, Vector4 &result) noexcept
	{
		using namespace DirectX;
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t); // Clamp value to 0 to 1
		t = t * t * (3.f - 2.f * t);
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::SmoothStep(const Vector4 &v1, const Vector4 &v2, float t) noexcept
	{
		using namespace DirectX;
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t); // Clamp value to 0 to 1
		t = t * t * (3.f - 2.f * t);
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Barycentric(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, float f, float g, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR x3 = XMLoadFloat4(&v3);
		XMVECTOR X = XMVectorBaryCentric(x1, x2, x3, f, g);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Barycentric(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, float f, float g) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR x3 = XMLoadFloat4(&v3);
		XMVECTOR X = XMVectorBaryCentric(x1, x2, x3, f, g);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::CatmullRom(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, const Vector4 &v4, float t, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR x3 = XMLoadFloat4(&v3);
		XMVECTOR x4 = XMLoadFloat4(&v4);
		XMVECTOR X = XMVectorCatmullRom(x1, x2, x3, x4, t);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::CatmullRom(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, const Vector4 &v4, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&v2);
		XMVECTOR x3 = XMLoadFloat4(&v3);
		XMVECTOR x4 = XMLoadFloat4(&v4);
		XMVECTOR X = XMVectorCatmullRom(x1, x2, x3, x4, t);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Hermite(const Vector4 &v1, const Vector4 &t1, const Vector4 &v2, const Vector4 &t2, float t, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&t1);
		XMVECTOR x3 = XMLoadFloat4(&v2);
		XMVECTOR x4 = XMLoadFloat4(&t2);
		XMVECTOR X = XMVectorHermite(x1, x2, x3, x4, t);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Hermite(const Vector4 &v1, const Vector4 &t1, const Vector4 &v2, const Vector4 &t2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(&v1);
		XMVECTOR x2 = XMLoadFloat4(&t1);
		XMVECTOR x3 = XMLoadFloat4(&v2);
		XMVECTOR x4 = XMLoadFloat4(&t2);
		XMVECTOR X = XMVectorHermite(x1, x2, x3, x4, t);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Reflect(const Vector4 &ivec, const Vector4 &nvec, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat4(&ivec);
		XMVECTOR n = XMLoadFloat4(&nvec);
		XMVECTOR X = XMVector4Reflect(i, n);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Reflect(const Vector4 &ivec, const Vector4 &nvec) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat4(&ivec);
		XMVECTOR n = XMLoadFloat4(&nvec);
		XMVECTOR X = XMVector4Reflect(i, n);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Refract(const Vector4 &ivec, const Vector4 &nvec, float refractionIndex, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat4(&ivec);
		XMVECTOR n = XMLoadFloat4(&nvec);
		XMVECTOR X = XMVector4Refract(i, n, refractionIndex);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Refract(const Vector4 &ivec, const Vector4 &nvec, float refractionIndex) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat4(&ivec);
		XMVECTOR n = XMLoadFloat4(&nvec);
		XMVECTOR X = XMVector4Refract(i, n, refractionIndex);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Transform(const Vector2 &v, const Quaternion &quat, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		X = XMVectorSelect(g_XMIdentityR3, X, g_XMSelect1110); // result.w = 1.f
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Transform(const Vector2 &v, const Quaternion &quat) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		X = XMVectorSelect(g_XMIdentityR3, X, g_XMSelect1110); // result.w = 1.f

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Transform(const Vector3 &v, const Quaternion &quat, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		X = XMVectorSelect(g_XMIdentityR3, X, g_XMSelect1110); // result.w = 1.f
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Transform(const Vector3 &v, const Quaternion &quat) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		X = XMVectorSelect(g_XMIdentityR3, X, g_XMSelect1110); // result.w = 1.f

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Transform(const Vector4 &v, const Quaternion &quat, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		X = XMVectorSelect(v1, X, g_XMSelect1110); // result.w = v.w
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Transform(const Vector4 &v, const Quaternion &quat) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		X = XMVectorSelect(v1, X, g_XMSelect1110); // result.w = v.w

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	void Vector4::Transform(const Vector4 &v, const Matrix &m, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector4Transform(v1, M);
		XMStoreFloat4(&result, X);
	}

	Vector4 Vector4::Transform(const Vector4 &v, const Matrix &m) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector4Transform(v1, M);

		Vector4 result;
		XMStoreFloat4(&result, X);
		return result;
	}

	_Use_decl_annotations_ void Vector4::Transform(const Vector4 *varray, size_t count, const Matrix &m, Vector4 *resultArray) noexcept
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector4TransformStream(resultArray, sizeof(XMFLOAT4), varray, sizeof(XMFLOAT4), count, M);
	}

	Vector4 operator+(const Vector4 &V1, const Vector4 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V1);
		XMVECTOR v2 = XMLoadFloat4(&V2);
		XMVECTOR X = XMVectorAdd(v1, v2);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	Vector4 operator-(const Vector4 &V1, const Vector4 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V1);
		XMVECTOR v2 = XMLoadFloat4(&V2);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	Vector4 operator*(const Vector4 &V1, const Vector4 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V1);
		XMVECTOR v2 = XMLoadFloat4(&V2);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	Vector4 operator*(const Vector4 &V, float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V);
		XMVECTOR X = XMVectorScale(v1, S);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	Vector4 operator/(const Vector4 &V1, const Vector4 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V1);
		XMVECTOR v2 = XMLoadFloat4(&V2);
		XMVECTOR X = XMVectorDivide(v1, v2);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	Vector4 operator/(const Vector4 &V, float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V);
		XMVECTOR X = XMVectorScale(v1, 1.f / S);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	Vector4 operator*(float S, const Vector4 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(&V);
		XMVECTOR X = XMVectorScale(v1, S);
		Vector4 R;
		XMStoreFloat4(&R, X);
		return R;
	}

	const Vector4
			Vector4::Zero(0.f, 0.f, 0.f, 0.f),
			Vector4::One(1.f, 1.f, 1.f, 1.f),
			Vector4::UnitX(1.f, 0.f, 0.f, 0.f),
			Vector4::UnitY(0.f, 1.f, 0.f, 0.f),
			Vector4::UnitZ(0.f, 0.f, 1.f, 0.f),
			Vector4::UnitW(0.f, 0.f, 0.f, 1.f);
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Vector4>::operator()(const Pazu::Math::Vector4 &V1, const Pazu::Math::Vector4 &V2) const noexcept
	{
		return ((V1.x < V2.x) || ((V1.x == V2.x) && (V1.y < V2.y)) || ((V1.x == V2.x) && (V1.y == V2.y) && (V1.z < V2.z)) || ((V1.x == V2.x) && (V1.y == V2.y) && (V1.z == V2.z) && (V1.w < V2.w)));
	}
} // namespace std

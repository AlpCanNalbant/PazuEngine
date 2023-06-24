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
#include "Vector4.h"
#include "Vector2.h"

namespace Pazu
{
	Vector2::Vector2()
			: XMFLOAT2(0.f, 0.f) {}

	Vector2::Vector2(_In_reads_(2) const float *pArray)
			: XMFLOAT2(pArray) {}

	Vector2::Vector2(DirectX::FXMVECTOR V)
	{
		XMStoreFloat2(this, V);
	}

	Vector2::Vector2(const XMFLOAT2 &V)
	{
		this->x = V.x;
		this->y = V.y;
	}

	Vector2::Vector2(const DirectX::XMVECTORF32 &F)
	{
		this->x = F.f[0];
		this->y = F.f[1];
	}

	Vector2::operator DirectX::XMVECTOR() const
	{
		return XMLoadFloat2(this);
	}

	bool Vector2::operator==(const Vector2 &V) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		return XMVector2Equal(v1, v2);
	}

	bool Vector2::operator!=(const Vector2 &V) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		return XMVector2NotEqual(v1, v2);
	}

	Vector2 &Vector2::operator=(const DirectX::XMVECTORF32 &F)
	{
		x = F.f[0];
		y = F.f[1];
		return *this;
	}

	Vector2 &Vector2::operator+=(const Vector2 &V)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreFloat2(this, X);
		return *this;
	}

	Vector2 &Vector2::operator-=(const Vector2 &V)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreFloat2(this, X);
		return *this;
	}

	Vector2 &Vector2::operator*=(const Vector2 &V)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreFloat2(this, X);
		return *this;
	}

	Vector2 &Vector2::operator*=(float S)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR X = XMVectorScale(v1, S);
		XMStoreFloat2(this, X);
		return *this;
	}

	Vector2 &Vector2::operator/=(float S)
	{
		using namespace DirectX;
		assert(S != 0.0f);
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR X = XMVectorScale(v1, 1.f / S);
		XMStoreFloat2(this, X);
		return *this;
	}

	Vector2 Vector2::operator+() const
	{
		return *this;
	}

	Vector2 Vector2::operator-() const
	{
		return Vector2(-x, -y);
	}

	bool Vector2::InBounds(const Vector2 &Bounds) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&Bounds);
		return XMVector2InBounds(v1, v2);
	}

	float Vector2::Length() const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR X = XMVector2Length(v1);
		return XMVectorGetX(X);
	}

	float Vector2::LengthSquared() const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR X = XMVector2LengthSq(v1);
		return XMVectorGetX(X);
	}

	float Vector2::Dot(const Vector2 &V) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		XMVECTOR X = XMVector2Dot(v1, v2);
		return XMVectorGetX(X);
	}

	void Vector2::Cross(const Vector2 &V, Vector2 &result) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		XMVECTOR R = XMVector2Cross(v1, v2);
		XMStoreFloat2(&result, R);
	}

	Vector2 Vector2::Cross(const Vector2 &V) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&V);
		XMVECTOR R = XMVector2Cross(v1, v2);

		Vector2 result;
		XMStoreFloat2(&result, R);
		return result;
	}

	void Vector2::Normalize()
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR X = XMVector2Normalize(v1);
		XMStoreFloat2(this, X);
	}

	void Vector2::Normalize(Vector2 &result) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR X = XMVector2Normalize(v1);
		XMStoreFloat2(&result, X);
	}

	void Vector2::Clamp(const Vector2 &vmin, const Vector2 &vmax)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&vmin);
		XMVECTOR v3 = XMLoadFloat2(&vmax);
		XMVECTOR X = XMVectorClamp(v1, v2, v3);
		XMStoreFloat2(this, X);
	}

	void Vector2::Clamp(const Vector2 &vmin, const Vector2 &vmax, Vector2 &result) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(this);
		XMVECTOR v2 = XMLoadFloat2(&vmin);
		XMVECTOR v3 = XMLoadFloat2(&vmax);
		XMVECTOR X = XMVectorClamp(v1, v2, v3);
		XMStoreFloat2(&result, X);
	}

	float Vector2::Distance(const Vector2 &v1, const Vector2 &v2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR V = XMVectorSubtract(x2, x1);
		XMVECTOR X = XMVector2Length(V);
		return XMVectorGetX(X);
	}

	float Vector2::DistanceSquared(const Vector2 &v1, const Vector2 &v2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR V = XMVectorSubtract(x2, x1);
		XMVECTOR X = XMVector2LengthSq(V);
		return XMVectorGetX(X);
	}

	void Vector2::Min(const Vector2 &v1, const Vector2 &v2, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorMin(x1, x2);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Min(const Vector2 &v1, const Vector2 &v2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorMin(x1, x2);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Max(const Vector2 &v1, const Vector2 &v2, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorMax(x1, x2);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Max(const Vector2 &v1, const Vector2 &v2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorMax(x1, x2);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Lerp(const Vector2 &v1, const Vector2 &v2, float t, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Lerp(const Vector2 &v1, const Vector2 &v2, float t)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::SmoothStep(const Vector2 &v1, const Vector2 &v2, float t, Vector2 &result)
	{
		using namespace DirectX;
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t); // Clamp value to 0 to 1
		t = t * t * (3.f - 2.f * t);
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::SmoothStep(const Vector2 &v1, const Vector2 &v2, float t)
	{
		using namespace DirectX;
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t); // Clamp value to 0 to 1
		t = t * t * (3.f - 2.f * t);
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Barycentric(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float f, float g, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR x3 = XMLoadFloat2(&v3);
		XMVECTOR X = XMVectorBaryCentric(x1, x2, x3, f, g);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Barycentric(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float f, float g)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR x3 = XMLoadFloat2(&v3);
		XMVECTOR X = XMVectorBaryCentric(x1, x2, x3, f, g);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::CatmullRom(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, float t, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR x3 = XMLoadFloat2(&v3);
		XMVECTOR x4 = XMLoadFloat2(&v4);
		XMVECTOR X = XMVectorCatmullRom(x1, x2, x3, x4, t);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::CatmullRom(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, float t)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&v2);
		XMVECTOR x3 = XMLoadFloat2(&v3);
		XMVECTOR x4 = XMLoadFloat2(&v4);
		XMVECTOR X = XMVectorCatmullRom(x1, x2, x3, x4, t);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Hermite(const Vector2 &v1, const Vector2 &t1, const Vector2 &v2, const Vector2 &t2, float t, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&t1);
		XMVECTOR x3 = XMLoadFloat2(&v2);
		XMVECTOR x4 = XMLoadFloat2(&t2);
		XMVECTOR X = XMVectorHermite(x1, x2, x3, x4, t);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Hermite(const Vector2 &v1, const Vector2 &t1, const Vector2 &v2, const Vector2 &t2, float t)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat2(&v1);
		XMVECTOR x2 = XMLoadFloat2(&t1);
		XMVECTOR x3 = XMLoadFloat2(&v2);
		XMVECTOR x4 = XMLoadFloat2(&t2);
		XMVECTOR X = XMVectorHermite(x1, x2, x3, x4, t);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Reflect(const Vector2 &ivec, const Vector2 &nvec, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat2(&ivec);
		XMVECTOR n = XMLoadFloat2(&nvec);
		XMVECTOR X = XMVector2Reflect(i, n);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Reflect(const Vector2 &ivec, const Vector2 &nvec)
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat2(&ivec);
		XMVECTOR n = XMLoadFloat2(&nvec);
		XMVECTOR X = XMVector2Reflect(i, n);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Refract(const Vector2 &ivec, const Vector2 &nvec, float refractionIndex, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat2(&ivec);
		XMVECTOR n = XMLoadFloat2(&nvec);
		XMVECTOR X = XMVector2Refract(i, n, refractionIndex);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Refract(const Vector2 &ivec, const Vector2 &nvec, float refractionIndex)
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat2(&ivec);
		XMVECTOR n = XMLoadFloat2(&nvec);
		XMVECTOR X = XMVector2Refract(i, n, refractionIndex);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Transform(const Vector2 &v, const Quaternion &quat, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Transform(const Vector2 &v, const Quaternion &quat)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	void Vector2::Transform(const Vector2 &v, const Matrix &m, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector2TransformCoord(v1, M);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::Transform(const Vector2 &v, const Matrix &m)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector2TransformCoord(v1, M);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	_Use_decl_annotations_ void Vector2::Transform(const Vector2 *varray, size_t count, const Matrix &m, Vector2 *resultArray)
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector2TransformCoordStream(resultArray, sizeof(XMFLOAT2), varray, sizeof(XMFLOAT2), count, M);
	}

	void Vector2::Transform(const Vector2 &v, const Matrix &m, Vector4 &result)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector2Transform(v1, M);
		XMStoreFloat4(&result, X);
	}

	_Use_decl_annotations_ void Vector2::Transform(const Vector2 *varray, size_t count, const Matrix &m, Vector4 *resultArray)
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector2TransformStream(resultArray, sizeof(XMFLOAT4), varray, sizeof(XMFLOAT2), count, M);
	}

	void Vector2::TransformNormal(const Vector2 &v, const Matrix &m, Vector2 &result)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector2TransformNormal(v1, M);
		XMStoreFloat2(&result, X);
	}

	Vector2 Vector2::TransformNormal(const Vector2 &v, const Matrix &m)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector2TransformNormal(v1, M);

		Vector2 result;
		XMStoreFloat2(&result, X);
		return result;
	}

	_Use_decl_annotations_ void Vector2::TransformNormal(const Vector2 *varray, size_t count, const Matrix &m, Vector2 *resultArray)
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector2TransformNormalStream(resultArray, sizeof(XMFLOAT2), varray, sizeof(XMFLOAT2), count, M);
	}

	const Vector2
			Vector2::Zero(0.f, 0.f),
			Vector2::One(1.f, 1.f),
			Vector2::UnitX(1.f, 0.f),
			Vector2::UnitY(0.f, 1.f);

	Vector2 operator+(const Vector2 &V1, const Vector2 &V2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V1);
		XMVECTOR v2 = XMLoadFloat2(&V2);
		XMVECTOR X = XMVectorAdd(v1, v2);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}

	Vector2 operator-(const Vector2 &V1, const Vector2 &V2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V1);
		XMVECTOR v2 = XMLoadFloat2(&V2);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}

	Vector2 operator*(const Vector2 &V1, const Vector2 &V2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V1);
		XMVECTOR v2 = XMLoadFloat2(&V2);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}

	Vector2 operator*(const Vector2 &V, float S)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V);
		XMVECTOR X = XMVectorScale(v1, S);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}

	Vector2 operator/(const Vector2 &V1, const Vector2 &V2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V1);
		XMVECTOR v2 = XMLoadFloat2(&V2);
		XMVECTOR X = XMVectorDivide(v1, v2);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}

	Vector2 operator/(const Vector2 &V, float S)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V);
		XMVECTOR X = XMVectorScale(v1, 1.f / S);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}

	Vector2 operator*(float S, const Vector2 &V)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat2(&V);
		XMVECTOR X = XMVectorScale(v1, S);
		Vector2 R;
		XMStoreFloat2(&R, X);
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Vector2>::operator()(const Pazu::Vector2 &V1, const Pazu::Vector2 &V2) const
	{
		return ((V1.x < V2.x) || ((V1.x == V2.x) && (V1.y < V2.y)));
	}
} // namespace std

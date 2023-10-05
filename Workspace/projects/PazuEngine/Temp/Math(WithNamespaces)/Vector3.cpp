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
#include "Vector4.h"
#include "Vector3.h"

namespace Pazu::Math
{
	Vector3::Vector3() noexcept
		: XMFLOAT3(0.f, 0.f, 0.f) {}

	Vector3::Vector3(_In_reads_(3) const float *pArray) noexcept
		: XMFLOAT3(pArray) {}

	Vector3::Vector3(DirectX::FXMVECTOR V) noexcept
	{
		XMStoreFloat3(this, V);
	}

	Vector3::Vector3(const XMFLOAT3 &V) noexcept
	{
		this->x = V.x;
		this->y = V.y;
		this->z = V.z;
	}

	Vector3::Vector3(const DirectX::XMVECTORF32 &F) noexcept
	{
		this->x = F.f[0];
		this->y = F.f[1];
		this->z = F.f[2];
	}

	Vector3::operator DirectX::XMVECTOR() const noexcept
	{
		return XMLoadFloat3(this);
	}

	bool Vector3::operator==(const Vector3 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		return XMVector3Equal(v1, v2);
	}

	bool Vector3::operator!=(const Vector3 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		return XMVector3NotEqual(v1, v2);
	}

	Vector3 &Vector3::operator=(const DirectX::XMVECTORF32 &F) noexcept
	{
		x = F.f[0];
		y = F.f[1];
		z = F.f[2];
		return *this;
	}

	Vector3 &Vector3::operator+=(const Vector3 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreFloat3(this, X);
		return *this;
	}

	Vector3 &Vector3::operator-=(const Vector3 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreFloat3(this, X);
		return *this;
	}

	Vector3 &Vector3::operator*=(const Vector3 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreFloat3(this, X);
		return *this;
	}

	Vector3 &Vector3::operator*=(float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVectorScale(v1, S);
		XMStoreFloat3(this, X);
		return *this;
	}

	Vector3 &Vector3::operator/=(float S) noexcept
	{
		using namespace DirectX;
		assert(S != 0.0f);
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVectorScale(v1, 1.f / S);
		XMStoreFloat3(this, X);
		return *this;
	}

	Vector3 Vector3::operator+() const noexcept
	{
		return *this;
	}

	Vector3 Vector3::operator-() const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVectorNegate(v1);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	bool Vector3::InBounds(const Vector3 &Bounds) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&Bounds);
		return XMVector3InBounds(v1, v2);
	}

	float Vector3::Length() const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVector3Length(v1);
		return XMVectorGetX(X);
	}

	float Vector3::LengthSquared() const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVector3LengthSq(v1);
		return XMVectorGetX(X);
	}

	float Vector3::Dot(const Vector3 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		XMVECTOR X = XMVector3Dot(v1, v2);
		return XMVectorGetX(X);
	}

	void Vector3::Cross(const Vector3 &V, Vector3 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		XMVECTOR R = XMVector3Cross(v1, v2);
		XMStoreFloat3(&result, R);
	}

	Vector3 Vector3::Cross(const Vector3 &V) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&V);
		XMVECTOR R = XMVector3Cross(v1, v2);

		Vector3 result;
		XMStoreFloat3(&result, R);
		return result;
	}

	void Vector3::Normalize() noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVector3Normalize(v1);
		XMStoreFloat3(this, X);
	}

	void Vector3::Normalize(Vector3 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR X = XMVector3Normalize(v1);
		XMStoreFloat3(&result, X);
	}

	void Vector3::Clamp(const Vector3 &vmin, const Vector3 &vmax) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&vmin);
		XMVECTOR v3 = XMLoadFloat3(&vmax);
		XMVECTOR X = XMVectorClamp(v1, v2, v3);
		XMStoreFloat3(this, X);
	}

	void Vector3::Clamp(const Vector3 &vmin, const Vector3 &vmax, Vector3 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(this);
		XMVECTOR v2 = XMLoadFloat3(&vmin);
		XMVECTOR v3 = XMLoadFloat3(&vmax);
		XMVECTOR X = XMVectorClamp(v1, v2, v3);
		XMStoreFloat3(&result, X);
	}

	float Vector3::Distance(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR V = XMVectorSubtract(x2, x1);
		XMVECTOR X = XMVector3Length(V);
		return XMVectorGetX(X);
	}

	float Vector3::DistanceSquared(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR V = XMVectorSubtract(x2, x1);
		XMVECTOR X = XMVector3LengthSq(V);
		return XMVectorGetX(X);
	}

	void Vector3::Min(const Vector3 &v1, const Vector3 &v2, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorMin(x1, x2);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Min(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorMin(x1, x2);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Max(const Vector3 &v1, const Vector3 &v2, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorMax(x1, x2);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Max(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorMax(x1, x2);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Lerp(const Vector3 &v1, const Vector3 &v2, float t, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Lerp(const Vector3 &v1, const Vector3 &v2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::SmoothStep(const Vector3 &v1, const Vector3 &v2, float t, Vector3 &result) noexcept
	{
		using namespace DirectX;
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t); // Clamp value to 0 to 1
		t = t * t * (3.f - 2.f * t);
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::SmoothStep(const Vector3 &v1, const Vector3 &v2, float t) noexcept
	{
		using namespace DirectX;
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t); // Clamp value to 0 to 1
		t = t * t * (3.f - 2.f * t);
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR X = XMVectorLerp(x1, x2, t);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Barycentric(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float f, float g, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR x3 = XMLoadFloat3(&v3);
		XMVECTOR X = XMVectorBaryCentric(x1, x2, x3, f, g);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Barycentric(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float f, float g) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR x3 = XMLoadFloat3(&v3);
		XMVECTOR X = XMVectorBaryCentric(x1, x2, x3, f, g);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::CatmullRom(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, float t, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR x3 = XMLoadFloat3(&v3);
		XMVECTOR x4 = XMLoadFloat3(&v4);
		XMVECTOR X = XMVectorCatmullRom(x1, x2, x3, x4, t);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::CatmullRom(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&v2);
		XMVECTOR x3 = XMLoadFloat3(&v3);
		XMVECTOR x4 = XMLoadFloat3(&v4);
		XMVECTOR X = XMVectorCatmullRom(x1, x2, x3, x4, t);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Hermite(const Vector3 &v1, const Vector3 &t1, const Vector3 &v2, const Vector3 &t2, float t, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&t1);
		XMVECTOR x3 = XMLoadFloat3(&v2);
		XMVECTOR x4 = XMLoadFloat3(&t2);
		XMVECTOR X = XMVectorHermite(x1, x2, x3, x4, t);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Hermite(const Vector3 &v1, const Vector3 &t1, const Vector3 &v2, const Vector3 &t2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat3(&v1);
		XMVECTOR x2 = XMLoadFloat3(&t1);
		XMVECTOR x3 = XMLoadFloat3(&v2);
		XMVECTOR x4 = XMLoadFloat3(&t2);
		XMVECTOR X = XMVectorHermite(x1, x2, x3, x4, t);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Reflect(const Vector3 &ivec, const Vector3 &nvec, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat3(&ivec);
		XMVECTOR n = XMLoadFloat3(&nvec);
		XMVECTOR X = XMVector3Reflect(i, n);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Reflect(const Vector3 &ivec, const Vector3 &nvec) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat3(&ivec);
		XMVECTOR n = XMLoadFloat3(&nvec);
		XMVECTOR X = XMVector3Reflect(i, n);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Refract(const Vector3 &ivec, const Vector3 &nvec, float refractionIndex, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat3(&ivec);
		XMVECTOR n = XMLoadFloat3(&nvec);
		XMVECTOR X = XMVector3Refract(i, n, refractionIndex);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Refract(const Vector3 &ivec, const Vector3 &nvec, float refractionIndex) noexcept
	{
		using namespace DirectX;
		XMVECTOR i = XMLoadFloat3(&ivec);
		XMVECTOR n = XMLoadFloat3(&nvec);
		XMVECTOR X = XMVector3Refract(i, n, refractionIndex);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Transform(const Vector3 &v, const Quaternion &quat, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Transform(const Vector3 &v, const Quaternion &quat) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMVECTOR q = XMLoadFloat4(&quat);
		XMVECTOR X = XMVector3Rotate(v1, q);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	void Vector3::Transform(const Vector3 &v, const Matrix &m, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector3TransformCoord(v1, M);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::Transform(const Vector3 &v, const Matrix &m) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector3TransformCoord(v1, M);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	_Use_decl_annotations_ void Vector3::Transform(const Vector3 *varray, size_t count, const Matrix &m, Vector3 *resultArray) noexcept
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector3TransformCoordStream(resultArray, sizeof(XMFLOAT3), varray, sizeof(XMFLOAT3), count, M);
	}

	void Vector3::Transform(const Vector3 &v, const Matrix &m, Vector4 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector3Transform(v1, M);
		XMStoreFloat4(&result, X);
	}

	_Use_decl_annotations_ void Vector3::Transform(const Vector3 *varray, size_t count, const Matrix &m, Vector4 *resultArray) noexcept
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector3TransformStream(resultArray, sizeof(XMFLOAT4), varray, sizeof(XMFLOAT3), count, M);
	}

	void Vector3::TransformNormal(const Vector3 &v, const Matrix &m, Vector3 &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector3TransformNormal(v1, M);
		XMStoreFloat3(&result, X);
	}

	Vector3 Vector3::TransformNormal(const Vector3 &v, const Matrix &m) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&v);
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVECTOR X = XMVector3TransformNormal(v1, M);

		Vector3 result;
		XMStoreFloat3(&result, X);
		return result;
	}

	_Use_decl_annotations_ void Vector3::TransformNormal(const Vector3 *varray, size_t count, const Matrix &m, Vector3 *resultArray) noexcept
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(&m);
		XMVector3TransformNormalStream(resultArray, sizeof(XMFLOAT3), varray, sizeof(XMFLOAT3), count, M);
	}

	const Vector3
		Vector3::Zero(0.f, 0.f, 0.f),
		Vector3::One(1.f, 1.f, 1.f),
		Vector3::UnitX(1.f, 0.f, 0.f),
		Vector3::UnitY(0.f, 1.f, 0.f),
		Vector3::UnitZ(0.f, 0.f, 1.f),
		Vector3::Up(0.f, 1.f, 0.f),
		Vector3::Down(0.f, -1.f, 0.f),
		Vector3::Right(1.f, 0.f, 0.f),
		Vector3::Left(-1.f, 0.f, 0.f),
		Vector3::Forward(0.f, 0.f, -1.f),
		Vector3::Backward(0.f, 0.f, 1.f);

	Vector3 operator+(const Vector3 &V1, const Vector3 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V1);
		XMVECTOR v2 = XMLoadFloat3(&V2);
		XMVECTOR X = XMVectorAdd(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	Vector3 operator-(const Vector3 &V1, const Vector3 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V1);
		XMVECTOR v2 = XMLoadFloat3(&V2);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	Vector3 operator*(const Vector3 &V1, const Vector3 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V1);
		XMVECTOR v2 = XMLoadFloat3(&V2);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	Vector3 operator*(const Vector3 &V, float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V);
		XMVECTOR X = XMVectorScale(v1, S);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	Vector3 operator/(const Vector3 &V1, const Vector3 &V2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V1);
		XMVECTOR v2 = XMLoadFloat3(&V2);
		XMVECTOR X = XMVectorDivide(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	Vector3 operator/(const Vector3 &V, float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V);
		XMVECTOR X = XMVectorScale(v1, 1.f / S);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	Vector3 operator*(float S, const Vector3 &V) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat3(&V);
		XMVECTOR X = XMVectorScale(v1, S);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Vector3>::operator()(const Pazu::Math::Vector3 &V1, const Pazu::Math::Vector3 &V2) const noexcept
	{
		return ((V1.x < V2.x) || ((V1.x == V2.x) && (V1.y < V2.y)) || ((V1.x == V2.x) && (V1.y == V2.y) && (V1.z < V2.z)));
	}
} // namespace std

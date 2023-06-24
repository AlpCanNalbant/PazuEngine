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
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix.h"
#include "Quaternion.h"

namespace Pazu::Math
{
	Quaternion::Quaternion() noexcept
			: XMFLOAT4(0.f, 0.f, 0.f, 1.f) {}

	Quaternion::Quaternion(const Vector3 &v, float scalar) noexcept
			: XMFLOAT4(v.x, v.y, v.z, scalar) {}

	Quaternion::Quaternion(const Vector4 &v) noexcept
			: XMFLOAT4(v.x, v.y, v.z, v.w) {}

	Quaternion::Quaternion(_In_reads_(4) const float *pArray) noexcept
			: XMFLOAT4(pArray) {}

	Quaternion::Quaternion(DirectX::FXMVECTOR V) noexcept
	{
		XMStoreFloat4(this, V);
	}

	Quaternion::Quaternion(const XMFLOAT4 &q) noexcept
	{
		this->x = q.x;
		this->y = q.y;
		this->z = q.z;
		this->w = q.w;
	}

	Quaternion::Quaternion(const DirectX::XMVECTORF32 &F) noexcept
	{
		this->x = F.f[0];
		this->y = F.f[1];
		this->z = F.f[2];
		this->w = F.f[3];
	}

	Quaternion::operator DirectX::XMVECTOR() const noexcept
	{
		return XMLoadFloat4(this);
	}

	bool Quaternion::operator==(const Quaternion &q) const noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		return XMQuaternionEqual(q1, q2);
	}

	bool Quaternion::operator!=(const Quaternion &q) const noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		return XMQuaternionNotEqual(q1, q2);
	}

	Quaternion &Quaternion::operator=(const DirectX::XMVECTORF32 &F) noexcept
	{
		x = F.f[0];
		y = F.f[1];
		z = F.f[2];
		w = F.f[3];
		return *this;
	}

	Quaternion &Quaternion::operator+=(const Quaternion &q) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		XMStoreFloat4(this, XMVectorAdd(q1, q2));
		return *this;
	}

	Quaternion &Quaternion::operator-=(const Quaternion &q) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		XMStoreFloat4(this, XMVectorSubtract(q1, q2));
		return *this;
	}

	Quaternion &Quaternion::operator*=(const Quaternion &q) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		XMStoreFloat4(this, XMQuaternionMultiply(q1, q2));
		return *this;
	}

	Quaternion &Quaternion::operator*=(float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(this, XMVectorScale(q, S));
		return *this;
	}

	Quaternion &Quaternion::operator/=(const Quaternion &q) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		q2 = XMQuaternionInverse(q2);
		XMStoreFloat4(this, XMQuaternionMultiply(q1, q2));
		return *this;
	}

	Quaternion Quaternion::operator+() const noexcept
	{
		return *this;
	}

	Quaternion Quaternion::operator-() const noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorNegate(q));
		return R;
	}

	float Quaternion::Length() const noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		return XMVectorGetX(XMQuaternionLength(q));
	}

	float Quaternion::LengthSquared() const noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		return XMVectorGetX(XMQuaternionLengthSq(q));
	}

	void Quaternion::Normalize() noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(this, XMQuaternionNormalize(q));
	}

	void Quaternion::Normalize(Quaternion &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMQuaternionNormalize(q));
	}

	void Quaternion::Conjugate() noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(this, XMQuaternionConjugate(q));
	}

	void Quaternion::Conjugate(Quaternion &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMQuaternionConjugate(q));
	}

	void Quaternion::Inverse(Quaternion &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMQuaternionInverse(q));
	}

	float Quaternion::Dot(const Quaternion &q) const noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		return XMVectorGetX(XMQuaternionDot(q1, q2));
	}

	Quaternion Quaternion::CreateFromAxisAngle(const Vector3 &axis, float angle) noexcept
	{
		using namespace DirectX;
		XMVECTOR a = XMLoadFloat3(&axis);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationAxis(a, angle));
		return R;
	}

	Quaternion Quaternion::CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept
	{
		using namespace DirectX;
		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationRollPitchYaw(pitch, yaw, roll));
		return R;
	}

	Quaternion Quaternion::CreateFromRotationMatrix(const Matrix &M) noexcept
	{
		using namespace DirectX;
		XMMATRIX M0 = XMLoadFloat4x4(&M);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationMatrix(M0));
		return R;
	}

	void Quaternion::Lerp(const Quaternion &q1, const Quaternion &q2, float t, Quaternion &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR Q0 = XMLoadFloat4(&q1);
		XMVECTOR Q1 = XMLoadFloat4(&q2);

		XMVECTOR dot = XMVector4Dot(Q0, Q1);

		XMVECTOR R;
		if (XMVector4GreaterOrEqual(dot, XMVectorZero()))
		{
			R = XMVectorLerp(Q0, Q1, t);
		}
		else
		{
			XMVECTOR tv = XMVectorReplicate(t);
			XMVECTOR t1v = XMVectorReplicate(1.f - t);
			XMVECTOR X0 = XMVectorMultiply(Q0, t1v);
			XMVECTOR X1 = XMVectorMultiply(Q1, tv);
			R = XMVectorSubtract(X0, X1);
		}

		XMStoreFloat4(&result, XMQuaternionNormalize(R));
	}

	Quaternion Quaternion::Lerp(const Quaternion &q1, const Quaternion &q2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR Q0 = XMLoadFloat4(&q1);
		XMVECTOR Q1 = XMLoadFloat4(&q2);

		XMVECTOR dot = XMVector4Dot(Q0, Q1);

		XMVECTOR R;
		if (XMVector4GreaterOrEqual(dot, XMVectorZero()))
		{
			R = XMVectorLerp(Q0, Q1, t);
		}
		else
		{
			XMVECTOR tv = XMVectorReplicate(t);
			XMVECTOR t1v = XMVectorReplicate(1.f - t);
			XMVECTOR X0 = XMVectorMultiply(Q0, t1v);
			XMVECTOR X1 = XMVectorMultiply(Q1, tv);
			R = XMVectorSubtract(X0, X1);
		}

		Quaternion result;
		XMStoreFloat4(&result, XMQuaternionNormalize(R));
		return result;
	}

	void Quaternion::Slerp(const Quaternion &q1, const Quaternion &q2, float t, Quaternion &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR Q0 = XMLoadFloat4(&q1);
		XMVECTOR Q1 = XMLoadFloat4(&q2);
		XMStoreFloat4(&result, XMQuaternionSlerp(Q0, Q1, t));
	}

	Quaternion Quaternion::Slerp(const Quaternion &q1, const Quaternion &q2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR Q0 = XMLoadFloat4(&q1);
		XMVECTOR Q1 = XMLoadFloat4(&q2);

		Quaternion result;
		XMStoreFloat4(&result, XMQuaternionSlerp(Q0, Q1, t));
		return result;
	}

	void Quaternion::Concatenate(const Quaternion &q1, const Quaternion &q2, Quaternion &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR Q0 = XMLoadFloat4(&q1);
		XMVECTOR Q1 = XMLoadFloat4(&q2);
		XMStoreFloat4(&result, XMQuaternionMultiply(Q1, Q0));
	}

	Quaternion Quaternion::Concatenate(const Quaternion &q1, const Quaternion &q2) noexcept
	{
		using namespace DirectX;
		XMVECTOR Q0 = XMLoadFloat4(&q1);
		XMVECTOR Q1 = XMLoadFloat4(&q2);

		Quaternion result;
		XMStoreFloat4(&result, XMQuaternionMultiply(Q1, Q0));
		return result;
	}

	const Quaternion
			Quaternion::Identity(0.f, 0.f, 0.f, 1.f);

	Quaternion operator+(const Quaternion &Q1, const Quaternion &Q2) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(&Q1);
		XMVECTOR q2 = XMLoadFloat4(&Q2);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorAdd(q1, q2));
		return R;
	}

	Quaternion operator-(const Quaternion &Q1, const Quaternion &Q2) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(&Q1);
		XMVECTOR q2 = XMLoadFloat4(&Q2);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorSubtract(q1, q2));
		return R;
	}

	Quaternion operator*(const Quaternion &Q1, const Quaternion &Q2) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(&Q1);
		XMVECTOR q2 = XMLoadFloat4(&Q2);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionMultiply(q1, q2));
		return R;
	}

	Quaternion operator*(const Quaternion &Q, float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR q = XMLoadFloat4(&Q);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorScale(q, S));
		return R;
	}

	Quaternion operator/(const Quaternion &Q1, const Quaternion &Q2) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(&Q1);
		XMVECTOR q2 = XMLoadFloat4(&Q2);
		q2 = XMQuaternionInverse(q2);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionMultiply(q1, q2));
		return R;
	}

	Quaternion operator*(float S, const Quaternion &Q) noexcept
	{
		using namespace DirectX;
		XMVECTOR q1 = XMLoadFloat4(&Q);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorScale(q1, S));
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Quaternion>::operator()(const Pazu::Math::Quaternion &Q1, const Pazu::Math::Quaternion &Q2) const noexcept
	{
		return ((Q1.x < Q2.x) || ((Q1.x == Q2.x) && (Q1.y < Q2.y)) || ((Q1.x == Q2.x) && (Q1.y == Q2.y) && (Q1.z < Q2.z)) || ((Q1.x == Q2.x) && (Q1.y == Q2.y) && (Q1.z == Q2.z) && (Q1.w < Q2.w)));
	}
} // namespace std

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
#include <XMath/DirectXMath.h>

namespace Pazu
{
	struct Vector3;
	struct Vector4;
	struct Matrix;

	struct Quaternion : public DirectX::XMFLOAT4
	{
		Quaternion();
		constexpr Quaternion(float ix, float iy, float iz, float iw);
		Quaternion(const Vector3 &v, float scalar);
		explicit Quaternion(const Vector4 &v);
		explicit Quaternion(_In_reads_(4) const float *pArray);
		Quaternion(DirectX::FXMVECTOR V);
		Quaternion(const XMFLOAT4 &q);
		explicit Quaternion(const DirectX::XMVECTORF32 &F);
		Quaternion(const Quaternion &) = default;
		Quaternion &operator=(const Quaternion &) = default;
		Quaternion(Quaternion &&) = default;
		Quaternion &operator=(Quaternion &&) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Quaternion &q) const;
		bool operator!=(const Quaternion &q) const;
		Quaternion &operator=(const DirectX::XMVECTORF32 &F);
		Quaternion &operator+=(const Quaternion &q);
		Quaternion &operator-=(const Quaternion &q);
		Quaternion &operator*=(const Quaternion &q);
		Quaternion &operator*=(float S);
		Quaternion &operator/=(const Quaternion &q);
		Quaternion operator+() const;
		Quaternion operator-() const;
		float Length() const;
		float LengthSquared() const;
		void Normalize();
		void Normalize(Quaternion &result) const;
		void Conjugate();
		void Conjugate(Quaternion &result) const;
		void Inverse(Quaternion &result) const;
		float Dot(const Quaternion &Q) const;
		static Quaternion CreateFromAxisAngle(const Vector3 &axis, float angle);
		static Quaternion CreateFromYawPitchRoll(float yaw, float pitch, float roll);
		static Quaternion CreateFromRotationMatrix(const Matrix &M);
		static void Lerp(const Quaternion &q1, const Quaternion &q2, float t, Quaternion &result);
		static Quaternion Lerp(const Quaternion &q1, const Quaternion &q2, float t);
		static void Slerp(const Quaternion &q1, const Quaternion &q2, float t, Quaternion &result);
		static Quaternion Slerp(const Quaternion &q1, const Quaternion &q2, float t);
		static void Concatenate(const Quaternion &q1, const Quaternion &q2, Quaternion &result);
		static Quaternion Concatenate(const Quaternion &q1, const Quaternion &q2);

		static const Quaternion
				Identity;
	};

	Quaternion operator+(const Quaternion &Q1, const Quaternion &Q2);
	Quaternion operator-(const Quaternion &Q1, const Quaternion &Q2);
	Quaternion operator*(const Quaternion &Q1, const Quaternion &Q2);
	Quaternion operator*(const Quaternion &Q, float S);
	Quaternion operator/(const Quaternion &Q1, const Quaternion &Q2);
	Quaternion operator*(float S, const Quaternion &Q);
} // namespace Pazu
#include "Quaternion.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Quaternion>
	{
		bool operator()(const Pazu::Quaternion &Q1, const Pazu::Quaternion &Q2) const;
	};
} // namespace std

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
	struct Matrix;
	struct Quaternion;
	struct Vector2;
	struct Vector3;

	struct Vector4 : public DirectX::XMFLOAT4
	{
		Vector4();
		constexpr explicit Vector4(float ix);
		constexpr Vector4(float ix, float iy, float iz, float iw);
		explicit Vector4(_In_reads_(4) const float *pArray);
		Vector4(DirectX::FXMVECTOR V);
		Vector4(const XMFLOAT4 &V);
		explicit Vector4(const DirectX::XMVECTORF32 &F);
		Vector4(const Vector4 &) = default;
		Vector4 &operator=(const Vector4 &) = default;
		Vector4(Vector4 &&) = default;
		Vector4 &operator=(Vector4 &&) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Vector4 &V) const;
		bool operator!=(const Vector4 &V) const;
		Vector4 &operator=(const DirectX::XMVECTORF32 &F);
		Vector4 &operator+=(const Vector4 &V);
		Vector4 &operator-=(const Vector4 &V);
		Vector4 &operator*=(const Vector4 &V);
		Vector4 &operator*=(float S);
		Vector4 &operator/=(float S);
		Vector4 operator+() const;
		Vector4 operator-() const;
		bool InBounds(const Vector4 &Bounds) const;
		float Length() const;
		float LengthSquared() const;
		float Dot(const Vector4 &V) const;
		void Cross(const Vector4 &v1, const Vector4 &v2, Vector4 &result) const;
		Vector4 Cross(const Vector4 &v1, const Vector4 &v2) const;
		void Normalize();
		void Normalize(Vector4 &result) const;
		void Clamp(const Vector4 &vmin, const Vector4 &vmax);
		void Clamp(const Vector4 &vmin, const Vector4 &vmax, Vector4 &result) const;
		static float Distance(const Vector4 &v1, const Vector4 &v2);
		static float DistanceSquared(const Vector4 &v1, const Vector4 &v2);
		static void Min(const Vector4 &v1, const Vector4 &v2, Vector4 &result);
		static Vector4 Min(const Vector4 &v1, const Vector4 &v2);
		static void Max(const Vector4 &v1, const Vector4 &v2, Vector4 &result);
		static Vector4 Max(const Vector4 &v1, const Vector4 &v2);
		static void Lerp(const Vector4 &v1, const Vector4 &v2, float t, Vector4 &result);
		static Vector4 Lerp(const Vector4 &v1, const Vector4 &v2, float t);
		static void SmoothStep(const Vector4 &v1, const Vector4 &v2, float t, Vector4 &result);
		static Vector4 SmoothStep(const Vector4 &v1, const Vector4 &v2, float t);
		static void Barycentric(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, float f, float g, Vector4 &result);
		static Vector4 Barycentric(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, float f, float g);
		static void CatmullRom(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, const Vector4 &v4, float t, Vector4 &result);
		static Vector4 CatmullRom(const Vector4 &v1, const Vector4 &v2, const Vector4 &v3, const Vector4 &v4, float t);
		static void Hermite(const Vector4 &v1, const Vector4 &t1, const Vector4 &v2, const Vector4 &t2, float t, Vector4 &result);
		static Vector4 Hermite(const Vector4 &v1, const Vector4 &t1, const Vector4 &v2, const Vector4 &t2, float t);
		static void Reflect(const Vector4 &ivec, const Vector4 &nvec, Vector4 &result);
		static Vector4 Reflect(const Vector4 &ivec, const Vector4 &nvec);
		static void Refract(const Vector4 &ivec, const Vector4 &nvec, float refractionIndex, Vector4 &result);
		static Vector4 Refract(const Vector4 &ivec, const Vector4 &nvec, float refractionIndex);
		static void Transform(const Vector2 &v, const Quaternion &quat, Vector4 &result);
		static Vector4 Transform(const Vector2 &v, const Quaternion &quat);
		static void Transform(const Vector3 &v, const Quaternion &quat, Vector4 &result);
		static Vector4 Transform(const Vector3 &v, const Quaternion &quat);
		static void Transform(const Vector4 &v, const Quaternion &quat, Vector4 &result);
		static Vector4 Transform(const Vector4 &v, const Quaternion &quat);
		static void Transform(const Vector4 &v, const Matrix &m, Vector4 &result);
		static Vector4 Transform(const Vector4 &v, const Matrix &m);
		static void Transform(_In_reads_(count) const Vector4 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector4 *resultArray);

		static const Vector4
				Zero,
				One,
				UnitX,
				UnitY,
				UnitZ,
				UnitW;
	};

	Vector4 operator+(const Vector4 &V1, const Vector4 &V2);
	Vector4 operator-(const Vector4 &V1, const Vector4 &V2);
	Vector4 operator*(const Vector4 &V1, const Vector4 &V2);
	Vector4 operator*(const Vector4 &V, float S);
	Vector4 operator/(const Vector4 &V1, const Vector4 &V2);
	Vector4 operator/(const Vector4 &V, float S);
	Vector4 operator*(float S, const Vector4 &V);
} // namespace Pazu
#include "Vector4.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Vector4>
	{
		bool operator()(const Pazu::Vector4 &V1, const Pazu::Vector4 &V2) const;
	};
} // namespace std

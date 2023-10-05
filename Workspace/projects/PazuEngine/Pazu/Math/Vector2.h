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
#include <XMath/DirectXMath.h>

namespace Pazu
{
	struct Matrix;
	struct Quaternion;
	struct Vector4;

	struct Vector2 : public DirectX::XMFLOAT2
	{
		Vector2();
		constexpr explicit Vector2(float ix);
		constexpr Vector2(float ix, float iy);
		explicit Vector2(_In_reads_(2) const float *pArray);
		Vector2(DirectX::FXMVECTOR V);
		Vector2(const XMFLOAT2 &V);
		explicit Vector2(const DirectX::XMVECTORF32 &F);
		Vector2(const Vector2 &) = default;
		Vector2 &operator=(const Vector2 &) = default;
		Vector2(Vector2 &&) = default;
		Vector2 &operator=(Vector2 &&) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Vector2 &V) const;
		bool operator!=(const Vector2 &V) const;
		Vector2 &operator=(const DirectX::XMVECTORF32 &F);
		Vector2 &operator+=(const Vector2 &V);
		Vector2 &operator-=(const Vector2 &V);
		Vector2 &operator*=(const Vector2 &V);
		Vector2 &operator*=(float S);
		Vector2 &operator/=(float S);
		Vector2 operator+() const;
		Vector2 operator-() const;
		bool InBounds(const Vector2 &Bounds) const;
		float Length() const;
		float LengthSquared() const;
		float Dot(const Vector2 &V) const;
		void Cross(const Vector2 &V, Vector2 &result) const;
		Vector2 Cross(const Vector2 &V) const;
		void Normalize();
		void Normalize(Vector2 &result) const;
		void Clamp(const Vector2 &vmin, const Vector2 &vmax);
		void Clamp(const Vector2 &vmin, const Vector2 &vmax, Vector2 &result) const;
		static float Distance(const Vector2 &v1, const Vector2 &v2);
		static float DistanceSquared(const Vector2 &v1, const Vector2 &v2);
		static void Min(const Vector2 &v1, const Vector2 &v2, Vector2 &result);
		static Vector2 Min(const Vector2 &v1, const Vector2 &v2);
		static void Max(const Vector2 &v1, const Vector2 &v2, Vector2 &result);
		static Vector2 Max(const Vector2 &v1, const Vector2 &v2);
		static void Lerp(const Vector2 &v1, const Vector2 &v2, float t, Vector2 &result);
		static Vector2 Lerp(const Vector2 &v1, const Vector2 &v2, float t);
		static void SmoothStep(const Vector2 &v1, const Vector2 &v2, float t, Vector2 &result);
		static Vector2 SmoothStep(const Vector2 &v1, const Vector2 &v2, float t);
		static void Barycentric(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float f, float g, Vector2 &result);
		static Vector2 Barycentric(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float f, float g);
		static void CatmullRom(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, float t, Vector2 &result);
		static Vector2 CatmullRom(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, float t);
		static void Hermite(const Vector2 &v1, const Vector2 &t1, const Vector2 &v2, const Vector2 &t2, float t, Vector2 &result);
		static Vector2 Hermite(const Vector2 &v1, const Vector2 &t1, const Vector2 &v2, const Vector2 &t2, float t);
		static void Reflect(const Vector2 &ivec, const Vector2 &nvec, Vector2 &result);
		static Vector2 Reflect(const Vector2 &ivec, const Vector2 &nvec);
		static void Refract(const Vector2 &ivec, const Vector2 &nvec, float refractionIndex, Vector2 &result);
		static Vector2 Refract(const Vector2 &ivec, const Vector2 &nvec, float refractionIndex);
		static void Transform(const Vector2 &v, const Quaternion &quat, Vector2 &result);
		static Vector2 Transform(const Vector2 &v, const Quaternion &quat);
		static void Transform(const Vector2 &v, const Matrix &m, Vector2 &result);
		static Vector2 Transform(const Vector2 &v, const Matrix &m);
		static void Transform(_In_reads_(count) const Vector2 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector2 *resultArray);
		static void Transform(const Vector2 &v, const Matrix &m, Vector4 &result);
		static void Transform(_In_reads_(count) const Vector2 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector4 *resultArray);
		static void TransformNormal(const Vector2 &v, const Matrix &m, Vector2 &result);
		static Vector2 TransformNormal(const Vector2 &v, const Matrix &m);
		static void TransformNormal(_In_reads_(count) const Vector2 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector2 *resultArray);

		static const Vector2
			Zero,
			One,
			UnitX,
			UnitY;
	};

	Vector2 operator+(const Vector2 &V1, const Vector2 &V2);
	Vector2 operator-(const Vector2 &V1, const Vector2 &V2);
	Vector2 operator*(const Vector2 &V1, const Vector2 &V2);
	Vector2 operator*(const Vector2 &V, float S);
	Vector2 operator/(const Vector2 &V1, const Vector2 &V2);
	Vector2 operator/(const Vector2 &V, float S);
	Vector2 operator*(float S, const Vector2 &V);
} // namespace Pazu
#include "Vector2.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Vector2>
	{
		bool operator()(const Pazu::Vector2 &V1, const Pazu::Vector2 &V2) const;
	};
} // namespace std

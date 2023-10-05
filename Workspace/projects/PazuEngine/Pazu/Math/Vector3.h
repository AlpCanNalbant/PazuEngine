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

	struct Vector3 : public DirectX::XMFLOAT3
	{
		Vector3();
		constexpr explicit Vector3(float ix);
		constexpr Vector3(float ix, float iy, float iz);
		explicit Vector3(_In_reads_(3) const float *pArray);
		Vector3(DirectX::FXMVECTOR V);
		Vector3(const XMFLOAT3 &V);
		explicit Vector3(const DirectX::XMVECTORF32 &F);
		Vector3(const Vector3 &) = default;
		Vector3 &operator=(const Vector3 &) = default;
		Vector3(Vector3 &&) = default;
		Vector3 &operator=(Vector3 &&) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Vector3 &V) const;
		bool operator!=(const Vector3 &V) const;
		Vector3 &operator=(const DirectX::XMVECTORF32 &F);
		Vector3 &operator+=(const Vector3 &V);
		Vector3 &operator-=(const Vector3 &V);
		Vector3 &operator*=(const Vector3 &V);
		Vector3 &operator*=(float S);
		Vector3 &operator/=(float S);
		Vector3 operator+() const;
		Vector3 operator-() const;
		bool InBounds(const Vector3 &Bounds) const;
		float Length() const;
		float LengthSquared() const;
		float Dot(const Vector3 &V) const;
		void Cross(const Vector3 &V, Vector3 &result) const;
		Vector3 Cross(const Vector3 &V) const;
		void Normalize();
		void Normalize(Vector3 &result) const;
		void Clamp(const Vector3 &vmin, const Vector3 &vmax);
		void Clamp(const Vector3 &vmin, const Vector3 &vmax, Vector3 &result) const;
		static float Distance(const Vector3 &v1, const Vector3 &v2);
		static float DistanceSquared(const Vector3 &v1, const Vector3 &v2);
		static void Min(const Vector3 &v1, const Vector3 &v2, Vector3 &result);
		static Vector3 Min(const Vector3 &v1, const Vector3 &v2);
		static void Max(const Vector3 &v1, const Vector3 &v2, Vector3 &result);
		static Vector3 Max(const Vector3 &v1, const Vector3 &v2);
		static void Lerp(const Vector3 &v1, const Vector3 &v2, float t, Vector3 &result);
		static Vector3 Lerp(const Vector3 &v1, const Vector3 &v2, float t);
		static void SmoothStep(const Vector3 &v1, const Vector3 &v2, float t, Vector3 &result);
		static Vector3 SmoothStep(const Vector3 &v1, const Vector3 &v2, float t);
		static void Barycentric(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float f, float g, Vector3 &result);
		static Vector3 Barycentric(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float f, float g);
		static void CatmullRom(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, float t, Vector3 &result);
		static Vector3 CatmullRom(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, float t);
		static void Hermite(const Vector3 &v1, const Vector3 &t1, const Vector3 &v2, const Vector3 &t2, float t, Vector3 &result);
		static Vector3 Hermite(const Vector3 &v1, const Vector3 &t1, const Vector3 &v2, const Vector3 &t2, float t);
		static void Reflect(const Vector3 &ivec, const Vector3 &nvec, Vector3 &result);
		static Vector3 Reflect(const Vector3 &ivec, const Vector3 &nvec);
		static void Refract(const Vector3 &ivec, const Vector3 &nvec, float refractionIndex, Vector3 &result);
		static Vector3 Refract(const Vector3 &ivec, const Vector3 &nvec, float refractionIndex);
		static void Transform(const Vector3 &v, const Quaternion &quat, Vector3 &result);
		static Vector3 Transform(const Vector3 &v, const Quaternion &quat);
		static void Transform(const Vector3 &v, const Matrix &m, Vector3 &result);
		static Vector3 Transform(const Vector3 &v, const Matrix &m);
		static void Transform(_In_reads_(count) const Vector3 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector3 *resultArray);
		static void Transform(const Vector3 &v, const Matrix &m, Vector4 &result);
		static void Transform(_In_reads_(count) const Vector3 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector4 *resultArray);
		static void TransformNormal(const Vector3 &v, const Matrix &m, Vector3 &result);
		static Vector3 TransformNormal(const Vector3 &v, const Matrix &m);
		static void TransformNormal(_In_reads_(count) const Vector3 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector3 *resultArray);

		static const Vector3
			Zero,
			One,
			UnitX,
			UnitY,
			UnitZ,
			Up,
			Down,
			Right,
			Left,
			Forward,
			Backward;
	};

	Vector3 operator+(const Vector3 &V1, const Vector3 &V2);
	Vector3 operator-(const Vector3 &V1, const Vector3 &V2);
	Vector3 operator*(const Vector3 &V1, const Vector3 &V2);
	Vector3 operator*(const Vector3 &V, float S);
	Vector3 operator/(const Vector3 &V1, const Vector3 &V2);
	Vector3 operator/(const Vector3 &V, float S);
	Vector3 operator*(float S, const Vector3 &V);
} // namespace Pazu
#include "Vector3.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Vector3>
	{
		bool operator()(const Pazu::Vector3 &V1, const Pazu::Vector3 &V2) const;
	};
} // namespace std

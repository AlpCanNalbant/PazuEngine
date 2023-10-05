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

namespace Pazu::Math
{
	struct Matrix;
	struct Quaternion;
	struct Vector4;

	struct Vector2 : public DirectX::XMFLOAT2
	{
		Vector2() noexcept;
		constexpr explicit Vector2(float ix) noexcept;
		constexpr Vector2(float ix, float iy) noexcept;
		explicit Vector2(_In_reads_(2) const float *pArray) noexcept;
		Vector2(DirectX::FXMVECTOR V) noexcept;
		Vector2(const XMFLOAT2 &V) noexcept;
		explicit Vector2(const DirectX::XMVECTORF32 &F) noexcept;
		Vector2(const Vector2 &) = default;
		Vector2 &operator=(const Vector2 &) = default;
		Vector2(Vector2 &&) = default;
		Vector2 &operator=(Vector2 &&) = default;
		operator DirectX::XMVECTOR() const noexcept;
		bool operator==(const Vector2 &V) const noexcept;
		bool operator!=(const Vector2 &V) const noexcept;
		Vector2 &operator=(const DirectX::XMVECTORF32 &F) noexcept;
		Vector2 &operator+=(const Vector2 &V) noexcept;
		Vector2 &operator-=(const Vector2 &V) noexcept;
		Vector2 &operator*=(const Vector2 &V) noexcept;
		Vector2 &operator*=(float S) noexcept;
		Vector2 &operator/=(float S) noexcept;
		Vector2 operator+() const noexcept;
		Vector2 operator-() const noexcept;
		bool InBounds(const Vector2 &Bounds) const noexcept;
		float Length() const noexcept;
		float LengthSquared() const noexcept;
		float Dot(const Vector2 &V) const noexcept;
		void Cross(const Vector2 &V, Vector2 &result) const noexcept;
		Vector2 Cross(const Vector2 &V) const noexcept;
		void Normalize() noexcept;
		void Normalize(Vector2 &result) const noexcept;
		void Clamp(const Vector2 &vmin, const Vector2 &vmax) noexcept;
		void Clamp(const Vector2 &vmin, const Vector2 &vmax, Vector2 &result) const noexcept;
		static float Distance(const Vector2 &v1, const Vector2 &v2) noexcept;
		static float DistanceSquared(const Vector2 &v1, const Vector2 &v2) noexcept;
		static void Min(const Vector2 &v1, const Vector2 &v2, Vector2 &result) noexcept;
		static Vector2 Min(const Vector2 &v1, const Vector2 &v2) noexcept;
		static void Max(const Vector2 &v1, const Vector2 &v2, Vector2 &result) noexcept;
		static Vector2 Max(const Vector2 &v1, const Vector2 &v2) noexcept;
		static void Lerp(const Vector2 &v1, const Vector2 &v2, float t, Vector2 &result) noexcept;
		static Vector2 Lerp(const Vector2 &v1, const Vector2 &v2, float t) noexcept;
		static void SmoothStep(const Vector2 &v1, const Vector2 &v2, float t, Vector2 &result) noexcept;
		static Vector2 SmoothStep(const Vector2 &v1, const Vector2 &v2, float t) noexcept;
		static void Barycentric(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float f, float g, Vector2 &result) noexcept;
		static Vector2 Barycentric(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float f, float g) noexcept;
		static void CatmullRom(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, float t, Vector2 &result) noexcept;
		static Vector2 CatmullRom(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, const Vector2 &v4, float t) noexcept;
		static void Hermite(const Vector2 &v1, const Vector2 &t1, const Vector2 &v2, const Vector2 &t2, float t, Vector2 &result) noexcept;
		static Vector2 Hermite(const Vector2 &v1, const Vector2 &t1, const Vector2 &v2, const Vector2 &t2, float t) noexcept;
		static void Reflect(const Vector2 &ivec, const Vector2 &nvec, Vector2 &result) noexcept;
		static Vector2 Reflect(const Vector2 &ivec, const Vector2 &nvec) noexcept;
		static void Refract(const Vector2 &ivec, const Vector2 &nvec, float refractionIndex, Vector2 &result) noexcept;
		static Vector2 Refract(const Vector2 &ivec, const Vector2 &nvec, float refractionIndex) noexcept;
		static void Transform(const Vector2 &v, const Quaternion &quat, Vector2 &result) noexcept;
		static Vector2 Transform(const Vector2 &v, const Quaternion &quat) noexcept;
		static void Transform(const Vector2 &v, const Matrix &m, Vector2 &result) noexcept;
		static Vector2 Transform(const Vector2 &v, const Matrix &m) noexcept;
		static void Transform(_In_reads_(count) const Vector2 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector2 *resultArray) noexcept;
		static void Transform(const Vector2 &v, const Matrix &m, Vector4 &result) noexcept;
		static void Transform(_In_reads_(count) const Vector2 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector4 *resultArray) noexcept;
		static void TransformNormal(const Vector2 &v, const Matrix &m, Vector2 &result) noexcept;
		static Vector2 TransformNormal(const Vector2 &v, const Matrix &m) noexcept;
		static void TransformNormal(_In_reads_(count) const Vector2 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector2 *resultArray) noexcept;

		static const Vector2
			Zero,
			One,
			UnitX,
			UnitY;
	};

	Vector2 operator+(const Vector2 &V1, const Vector2 &V2) noexcept;
	Vector2 operator-(const Vector2 &V1, const Vector2 &V2) noexcept;
	Vector2 operator*(const Vector2 &V1, const Vector2 &V2) noexcept;
	Vector2 operator*(const Vector2 &V, float S) noexcept;
	Vector2 operator/(const Vector2 &V1, const Vector2 &V2) noexcept;
	Vector2 operator/(const Vector2 &V, float S) noexcept;
	Vector2 operator*(float S, const Vector2 &V) noexcept;
} // namespace Pazu
#include "Vector2.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Vector2>
	{
		bool operator()(const Pazu::Math::Vector2 &V1, const Pazu::Math::Vector2 &V2) const noexcept;
	};
} // namespace std

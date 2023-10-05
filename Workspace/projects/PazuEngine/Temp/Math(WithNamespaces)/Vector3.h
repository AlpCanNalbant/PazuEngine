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

	struct Vector3 : public DirectX::XMFLOAT3
	{
		Vector3() noexcept;
		constexpr explicit Vector3(float ix) noexcept;
		constexpr Vector3(float ix, float iy, float iz) noexcept;
		explicit Vector3(_In_reads_(3) const float *pArray) noexcept;
		Vector3(DirectX::FXMVECTOR V) noexcept;
		Vector3(const XMFLOAT3 &V) noexcept;
		explicit Vector3(const DirectX::XMVECTORF32 &F) noexcept;
		Vector3(const Vector3 &) = default;
		Vector3 &operator=(const Vector3 &) = default;
		Vector3(Vector3 &&) = default;
		Vector3 &operator=(Vector3 &&) = default;
		operator DirectX::XMVECTOR() const noexcept;
		bool operator==(const Vector3 &V) const noexcept;
		bool operator!=(const Vector3 &V) const noexcept;
		Vector3 &operator=(const DirectX::XMVECTORF32 &F) noexcept;
		Vector3 &operator+=(const Vector3 &V) noexcept;
		Vector3 &operator-=(const Vector3 &V) noexcept;
		Vector3 &operator*=(const Vector3 &V) noexcept;
		Vector3 &operator*=(float S) noexcept;
		Vector3 &operator/=(float S) noexcept;
		Vector3 operator+() const noexcept;
		Vector3 operator-() const noexcept;
		bool InBounds(const Vector3 &Bounds) const noexcept;
		float Length() const noexcept;
		float LengthSquared() const noexcept;
		float Dot(const Vector3 &V) const noexcept;
		void Cross(const Vector3 &V, Vector3 &result) const noexcept;
		Vector3 Cross(const Vector3 &V) const noexcept;
		void Normalize() noexcept;
		void Normalize(Vector3 &result) const noexcept;
		void Clamp(const Vector3 &vmin, const Vector3 &vmax) noexcept;
		void Clamp(const Vector3 &vmin, const Vector3 &vmax, Vector3 &result) const noexcept;
		static float Distance(const Vector3 &v1, const Vector3 &v2) noexcept;
		static float DistanceSquared(const Vector3 &v1, const Vector3 &v2) noexcept;
		static void Min(const Vector3 &v1, const Vector3 &v2, Vector3 &result) noexcept;
		static Vector3 Min(const Vector3 &v1, const Vector3 &v2) noexcept;
		static void Max(const Vector3 &v1, const Vector3 &v2, Vector3 &result) noexcept;
		static Vector3 Max(const Vector3 &v1, const Vector3 &v2) noexcept;
		static void Lerp(const Vector3 &v1, const Vector3 &v2, float t, Vector3 &result) noexcept;
		static Vector3 Lerp(const Vector3 &v1, const Vector3 &v2, float t) noexcept;
		static void SmoothStep(const Vector3 &v1, const Vector3 &v2, float t, Vector3 &result) noexcept;
		static Vector3 SmoothStep(const Vector3 &v1, const Vector3 &v2, float t) noexcept;
		static void Barycentric(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float f, float g, Vector3 &result) noexcept;
		static Vector3 Barycentric(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float f, float g) noexcept;
		static void CatmullRom(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, float t, Vector3 &result) noexcept;
		static Vector3 CatmullRom(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &v4, float t) noexcept;
		static void Hermite(const Vector3 &v1, const Vector3 &t1, const Vector3 &v2, const Vector3 &t2, float t, Vector3 &result) noexcept;
		static Vector3 Hermite(const Vector3 &v1, const Vector3 &t1, const Vector3 &v2, const Vector3 &t2, float t) noexcept;
		static void Reflect(const Vector3 &ivec, const Vector3 &nvec, Vector3 &result) noexcept;
		static Vector3 Reflect(const Vector3 &ivec, const Vector3 &nvec) noexcept;
		static void Refract(const Vector3 &ivec, const Vector3 &nvec, float refractionIndex, Vector3 &result) noexcept;
		static Vector3 Refract(const Vector3 &ivec, const Vector3 &nvec, float refractionIndex) noexcept;
		static void Transform(const Vector3 &v, const Quaternion &quat, Vector3 &result) noexcept;
		static Vector3 Transform(const Vector3 &v, const Quaternion &quat) noexcept;
		static void Transform(const Vector3 &v, const Matrix &m, Vector3 &result) noexcept;
		static Vector3 Transform(const Vector3 &v, const Matrix &m) noexcept;
		static void Transform(_In_reads_(count) const Vector3 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector3 *resultArray) noexcept;
		static void Transform(const Vector3 &v, const Matrix &m, Vector4 &result) noexcept;
		static void Transform(_In_reads_(count) const Vector3 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector4 *resultArray) noexcept;
		static void TransformNormal(const Vector3 &v, const Matrix &m, Vector3 &result) noexcept;
		static Vector3 TransformNormal(const Vector3 &v, const Matrix &m) noexcept;
		static void TransformNormal(_In_reads_(count) const Vector3 *varray, size_t count, const Matrix &m, _Out_writes_(count) Vector3 *resultArray) noexcept;

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

	Vector3 operator+(const Vector3 &V1, const Vector3 &V2) noexcept;
	Vector3 operator-(const Vector3 &V1, const Vector3 &V2) noexcept;
	Vector3 operator*(const Vector3 &V1, const Vector3 &V2) noexcept;
	Vector3 operator*(const Vector3 &V, float S) noexcept;
	Vector3 operator/(const Vector3 &V1, const Vector3 &V2) noexcept;
	Vector3 operator/(const Vector3 &V, float S) noexcept;
	Vector3 operator*(float S, const Vector3 &V) noexcept;
} // namespace Pazu
#include "Vector3.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Vector3>
	{
		bool operator()(const Pazu::Math::Vector3 &V1, const Pazu::Math::Vector3 &V2) const noexcept;
	};
} // namespace std

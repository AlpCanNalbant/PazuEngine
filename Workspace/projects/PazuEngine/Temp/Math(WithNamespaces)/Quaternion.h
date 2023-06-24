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

namespace Pazu::Math
{
	struct Vector3;
	struct Vector4;
	struct Matrix;

	struct Quaternion : public DirectX::XMFLOAT4
	{
		Quaternion() noexcept;
		constexpr Quaternion(float ix, float iy, float iz, float iw) noexcept;
		Quaternion(const Vector3 &v, float scalar) noexcept;
		explicit Quaternion(const Vector4 &v) noexcept;
		explicit Quaternion(_In_reads_(4) const float *pArray) noexcept;
		Quaternion(DirectX::FXMVECTOR V) noexcept;
		Quaternion(const XMFLOAT4 &q) noexcept;
		explicit Quaternion(const DirectX::XMVECTORF32 &F) noexcept;
		Quaternion(const Quaternion &) = default;
		Quaternion &operator=(const Quaternion &) = default;
		Quaternion(Quaternion &&) = default;
		Quaternion &operator=(Quaternion &&) = default;
		operator DirectX::XMVECTOR() const noexcept;
		bool operator==(const Quaternion &q) const noexcept;
		bool operator!=(const Quaternion &q) const noexcept;
		Quaternion &operator=(const DirectX::XMVECTORF32 &F) noexcept;
		Quaternion &operator+=(const Quaternion &q) noexcept;
		Quaternion &operator-=(const Quaternion &q) noexcept;
		Quaternion &operator*=(const Quaternion &q) noexcept;
		Quaternion &operator*=(float S) noexcept;
		Quaternion &operator/=(const Quaternion &q) noexcept;
		Quaternion operator+() const noexcept;
		Quaternion operator-() const noexcept;
		float Length() const noexcept;
		float LengthSquared() const noexcept;
		void Normalize() noexcept;
		void Normalize(Quaternion &result) const noexcept;
		void Conjugate() noexcept;
		void Conjugate(Quaternion &result) const noexcept;
		void Inverse(Quaternion &result) const noexcept;
		float Dot(const Quaternion &Q) const noexcept;
		static Quaternion CreateFromAxisAngle(const Vector3 &axis, float angle) noexcept;
		static Quaternion CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept;
		static Quaternion CreateFromRotationMatrix(const Matrix &M) noexcept;
		static void Lerp(const Quaternion &q1, const Quaternion &q2, float t, Quaternion &result) noexcept;
		static Quaternion Lerp(const Quaternion &q1, const Quaternion &q2, float t) noexcept;
		static void Slerp(const Quaternion &q1, const Quaternion &q2, float t, Quaternion &result) noexcept;
		static Quaternion Slerp(const Quaternion &q1, const Quaternion &q2, float t) noexcept;
		static void Concatenate(const Quaternion &q1, const Quaternion &q2, Quaternion &result) noexcept;
		static Quaternion Concatenate(const Quaternion &q1, const Quaternion &q2) noexcept;

		static const Quaternion
				Identity;
	};

	Quaternion operator+(const Quaternion &Q1, const Quaternion &Q2) noexcept;
	Quaternion operator-(const Quaternion &Q1, const Quaternion &Q2) noexcept;
	Quaternion operator*(const Quaternion &Q1, const Quaternion &Q2) noexcept;
	Quaternion operator*(const Quaternion &Q, float S) noexcept;
	Quaternion operator/(const Quaternion &Q1, const Quaternion &Q2) noexcept;
	Quaternion operator*(float S, const Quaternion &Q) noexcept;
} // namespace Pazu
#include "Quaternion.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Quaternion>
	{
		bool operator()(const Pazu::Math::Quaternion &Q1, const Pazu::Math::Quaternion &Q2) const noexcept;
	};
} // namespace std

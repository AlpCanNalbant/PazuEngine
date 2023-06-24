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
	struct Quaternion;

	struct Plane : public DirectX::XMFLOAT4
	{
		Plane() noexcept;
		constexpr Plane(float ix, float iy, float iz, float iw) noexcept;
		Plane(const Vector3 &normal, float d) noexcept;
		Plane(const Vector3 &point1, const Vector3 &point2, const Vector3 &point3) noexcept;
		Plane(const Vector3 &point, const Vector3 &normal) noexcept;
		explicit Plane(const Vector4 &v) noexcept;
		explicit Plane(_In_reads_(4) const float *pArray) noexcept;
		Plane(DirectX::FXMVECTOR V) noexcept;
		Plane(const XMFLOAT4 &p) noexcept;
		explicit Plane(const DirectX::XMVECTORF32 &F) noexcept;
		Plane(const Plane &) = default;
		Plane &operator=(const Plane &) = default;
		Plane(Plane &&) = default;
		Plane &operator=(Plane &&) = default;
		operator DirectX::XMVECTOR() const noexcept;
		bool operator==(const Plane &p) const noexcept;
		bool operator!=(const Plane &p) const noexcept;
		Plane &operator=(const DirectX::XMVECTORF32 &F) noexcept;
		Vector3 Normal() const noexcept;
		void Normal(const Vector3 &normal) noexcept;
		float D() const noexcept;
		void D(float d) noexcept;
		void Normalize() noexcept;
		void Normalize(Plane &result) const noexcept;
		float Dot(const Vector4 &v) const noexcept;
		float DotCoordinate(const Vector3 &position) const noexcept;
		float DotNormal(const Vector3 &normal) const noexcept;
		static void Transform(const Plane &plane, const Matrix &M, Plane &result) noexcept;
		static Plane Transform(const Plane &plane, const Matrix &M) noexcept;
		static void Transform(const Plane &plane, const Quaternion &rotation, Plane &result) noexcept;
		static Plane Transform(const Plane &plane, const Quaternion &rotation) noexcept;
	};
} // namespace Pazu
#include "Plane.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Plane>
	{
		bool operator()(const Pazu::Math::Plane &P1, const Pazu::Math::Plane &P2) const noexcept;
	};
} // namespace std

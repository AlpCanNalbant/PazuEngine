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
	struct Quaternion;

	struct Plane : public DirectX::XMFLOAT4
	{
		Plane();
		constexpr Plane(float ix, float iy, float iz, float iw);
		Plane(const Vector3 &normal, float d);
		Plane(const Vector3 &point1, const Vector3 &point2, const Vector3 &point3);
		Plane(const Vector3 &point, const Vector3 &normal);
		explicit Plane(const Vector4 &v);
		explicit Plane(_In_reads_(4) const float *pArray);
		Plane(DirectX::FXMVECTOR V);
		Plane(const XMFLOAT4 &p);
		explicit Plane(const DirectX::XMVECTORF32 &F);
		Plane(const Plane &) = default;
		Plane &operator=(const Plane &) = default;
		Plane(Plane &&) = default;
		Plane &operator=(Plane &&) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Plane &p) const;
		bool operator!=(const Plane &p) const;
		Plane &operator=(const DirectX::XMVECTORF32 &F);
		Vector3 Normal() const;
		void Normal(const Vector3 &normal);
		float D() const;
		void D(float d);
		void Normalize();
		void Normalize(Plane &result) const;
		float Dot(const Vector4 &v) const;
		float DotCoordinate(const Vector3 &position) const;
		float DotNormal(const Vector3 &normal) const;
		static void Transform(const Plane &plane, const Matrix &M, Plane &result);
		static Plane Transform(const Plane &plane, const Matrix &M);
		static void Transform(const Plane &plane, const Quaternion &rotation, Plane &result);
		static Plane Transform(const Plane &plane, const Quaternion &rotation);
	};
} // namespace Pazu
#include "Plane.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Plane>
	{
		bool operator()(const Pazu::Plane &P1, const Pazu::Plane &P2) const;
	};
} // namespace std

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

namespace Pazu
{
	struct Vector3;
	struct Matrix;

	class Viewport
	{
	public:
		constexpr Viewport() = default;
		constexpr Viewport(float ix, float iy, float iw, float ih, float iminz = 0.f, float imaxz = 1.f);
		Viewport(const Viewport &) = default;
		Viewport &operator=(const Viewport &) = default;
		Viewport(Viewport &&) = default;
		Viewport &operator=(Viewport &&) = default;
		bool operator==(const Viewport &vp) const;
		bool operator!=(const Viewport &vp) const;
		float AspectRatio() const;
		Vector3 Project(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world) const;
		void Project(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world, Vector3 &result) const;
		Vector3 Unproject(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world) const;
		void Unproject(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world, Vector3 &result) const;

		float x{0.f}, y{0.f};
		float width{0.f}, height{0.f};
		float minDepth{0.f}, maxDepth{1.f};
	};
} // namespace Pazu
#include "Viewport.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Viewport>
	{
		bool operator()(const Pazu::Viewport &vp1, const Pazu::Viewport &vp2) const;
	};
} // namespace std

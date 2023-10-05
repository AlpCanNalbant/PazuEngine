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

namespace Pazu::Math
{
	struct Vector3;
	struct Matrix;

	class Viewport
	{
	public:
		constexpr Viewport() noexcept = default;
		constexpr Viewport(float ix, float iy, float iw, float ih, float iminz = 0.f, float imaxz = 1.f) noexcept;
		Viewport(const Viewport &) = default;
		Viewport &operator=(const Viewport &) = default;
		Viewport(Viewport &&) = default;
		Viewport &operator=(Viewport &&) = default;
		bool operator==(const Viewport &vp) const noexcept;
		bool operator!=(const Viewport &vp) const noexcept;
		float AspectRatio() const noexcept;
		Vector3 Project(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world) const noexcept;
		void Project(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world, Vector3 &result) const noexcept;
		Vector3 Unproject(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world) const noexcept;
		void Unproject(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world, Vector3 &result) const noexcept;

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
	struct less<Pazu::Math::Viewport>
	{
		bool operator()(const Pazu::Math::Viewport &vp1, const Pazu::Math::Viewport &vp2) const noexcept;
	};
} // namespace std

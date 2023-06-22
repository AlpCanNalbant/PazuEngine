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

namespace Pazu::Math
{
	struct Vector2;

	struct Rectangle
	{
		constexpr Rectangle() noexcept = default;
		constexpr Rectangle(long ix, long iy, long iw, long ih) noexcept;
		Rectangle(const Rectangle &) = default;
		Rectangle &operator=(const Rectangle &) = default;
		Rectangle(Rectangle &&) = default;
		Rectangle &operator=(Rectangle &&) = default;
		bool operator==(const Rectangle &r) const noexcept;
		bool operator!=(const Rectangle &r) const noexcept;
		Vector2 Location() const noexcept;
		Vector2 Center() const noexcept;
		bool Empty() const noexcept;
		bool Contains(long ix, long iy) const noexcept;
		bool Contains(const Vector2 &point) const noexcept;
		bool Contains(const Rectangle &r) const noexcept;
		void Inflate(long horizAmount, long vertAmount) noexcept;
		bool Intersects(const Rectangle &r) const noexcept;
		void Offset(long ox, long oy) noexcept;
		static Rectangle Intersect(const Rectangle &ra, const Rectangle &rb) noexcept;
		static Rectangle Union(const Rectangle &ra, const Rectangle &rb) noexcept;

		long x{0}, y{0};
		long width{0}, height{0};
	};
} // namespace Pazu
#include "Rectangle.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Rectangle>
	{
		bool operator()(const Pazu::Math::Rectangle &r1, const Pazu::Math::Rectangle &r2) const noexcept;
	};
} // namespace std

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

namespace Pazu
{
	struct Vector2;

	struct Rectangle
	{
		constexpr Rectangle() = default;
		constexpr Rectangle(long ix, long iy, long iw, long ih);
		Rectangle(const Rectangle &) = default;
		Rectangle &operator=(const Rectangle &) = default;
		Rectangle(Rectangle &&) = default;
		Rectangle &operator=(Rectangle &&) = default;
		bool operator==(const Rectangle &r) const;
		bool operator!=(const Rectangle &r) const;
		Vector2 Location() const;
		Vector2 Center() const;
		bool Empty() const;
		bool Contains(long ix, long iy) const;
		bool Contains(const Vector2 &point) const;
		bool Contains(const Rectangle &r) const;
		void Inflate(long horizAmount, long vertAmount);
		bool Intersects(const Rectangle &r) const;
		void Offset(long ox, long oy);
		static Rectangle Intersect(const Rectangle &ra, const Rectangle &rb);
		static Rectangle Union(const Rectangle &ra, const Rectangle &rb);

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
	struct less<Pazu::Rectangle>
	{
		bool operator()(const Pazu::Rectangle &r1, const Pazu::Rectangle &r2) const;
	};
} // namespace std

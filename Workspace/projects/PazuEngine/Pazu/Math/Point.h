// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <XMath/DirectXMath.h>

namespace Pazu
{
	struct Point : public DirectX::XMINT2
	{
		Point();
		constexpr explicit Point(int value);
		constexpr Point(int x, int y);
		explicit Point(_In_reads_(2) const int *array);
		Point(DirectX::FXMVECTOR xmVector);
		Point(const XMINT2 &xmInt2);
		Point(const DirectX::XMVECTORI32 &xmVectorI32);
		Point(const Point &other) = default;
		Point &operator=(const Point &other) = default;
		Point(Point &&temp) = default;
		Point &operator=(Point &&temp) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Point &point) const;
		bool operator!=(const Point &point) const;
		Point &operator=(const DirectX::XMVECTORI32 &xmVectorI32);
		Point &operator+=(const Point &point);
		Point &operator-=(const Point &point);
		Point &operator*=(const Point &point);
		Point &operator*=(int value);
		Point &operator/=(int value);
		Point operator+() const;
		Point operator-() const;
		constexpr bool Empty() const;
		std::string ToString() const;

		static const Point
			Zero,
			One,
			UnitX,
			UnitY;
	};

	Point operator+(const Point &point1, const Point &point2);
	Point operator-(const Point &point1, const Point &point2);
	Point operator*(const Point &point1, const Point &point2);
	Point operator*(const Point &point, int value);
	Point operator/(const Point &point1, const Point &point2);
	Point operator/(const Point &point, int value);
	Point operator*(int value, const Point &point);
} // namespace Pazu
#include "Point.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Point>
	{
		bool operator()(const Pazu::Point &point1, const Pazu::Point &point2) const;
	};
} // namespace std

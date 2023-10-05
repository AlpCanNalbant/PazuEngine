// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <string>
#include <XMath/DirectXMath.h>

namespace Pazu::Math
{
	struct Point : public DirectX::XMINT2
	{
		Point() noexcept;
		constexpr explicit Point(int value) noexcept;
		constexpr Point(int x, int y) noexcept;
		explicit Point(_In_reads_(2) const int *array) noexcept;
		Point(DirectX::FXMVECTOR xmVector) noexcept;
		Point(const XMINT2 &xmInt2) noexcept;
		Point(const DirectX::XMVECTORI32 &xmVectorI32) noexcept;
		Point(const Point &other) = default;
		Point &operator=(const Point &other) = default;
		Point(Point &&temp) = default;
		Point &operator=(Point &&temp) = default;
		operator DirectX::XMVECTOR() const noexcept;
		bool operator==(const Point &point) const noexcept;
		bool operator!=(const Point &point) const noexcept;
		Point &operator=(const DirectX::XMVECTORI32 &xmVectorI32) noexcept;
		Point &operator+=(const Point &point) noexcept;
		Point &operator-=(const Point &point) noexcept;
		Point &operator*=(const Point &point) noexcept;
		Point &operator*=(int value) noexcept;
		Point &operator/=(int value) noexcept;
		Point operator+() const noexcept;
		Point operator-() const noexcept;
		constexpr bool Empty() const noexcept;
		String ToString() const noexcept;

		static const Point
			Zero,
			One,
			UnitX,
			UnitY;
	};

	Point operator+(const Point &point1, const Point &point2) noexcept;
	Point operator-(const Point &point1, const Point &point2) noexcept;
	Point operator*(const Point &point1, const Point &point2) noexcept;
	Point operator*(const Point &point, int value) noexcept;
	Point operator/(const Point &point1, const Point &point2) noexcept;
	Point operator/(const Point &point, int value) noexcept;
	Point operator*(int value, const Point &point) noexcept;
} // namespace Pazu
#include "Point.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Point>
	{
		bool operator()(const Pazu::Math::Point &point1, const Pazu::Math::Point &point2) const noexcept;
	};
} // namespace std

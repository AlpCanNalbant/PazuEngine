// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include <functional>
#include "Point.h"

namespace Pazu::Math
{
	Point::Point() noexcept
		: XMINT2(0, 0) {}

	Point::Point(_In_reads_(2) const int *array) noexcept
		: XMINT2(array) {}

	Point::Point(DirectX::FXMVECTOR v) noexcept
	{
		XMStoreSInt2(this, v);
	}

	Point::Point(const XMINT2 &xmInt2) noexcept
	{
		this->x = xmInt2.x;
		this->y = xmInt2.y;
	}

	Point::Point(const DirectX::XMVECTORI32 &xmVectorI32) noexcept
	{
		this->x = xmVectorI32.i[0];
		this->y = xmVectorI32.i[1];
	}

	Point::operator DirectX::XMVECTOR() const noexcept
	{
		return XMLoadSInt2(this);
	}

	bool Point::operator==(const Point &point) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&point);
		return XMVector2NotEqual(v1, v2);
	}

	bool Point::operator!=(const Point &point) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&point);
		return XMVector2NotEqual(v1, v2);
	}

	Point &Point::operator=(const DirectX::XMVECTORI32 &xmVectorI32) noexcept
	{
		x = xmVectorI32.i[0];
		y = xmVectorI32.i[1];
		return *this;
	}

	Point &Point::operator+=(const Point &point) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&point);
		XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreSInt2(this, X);
		return *this;
	}

	Point &Point::operator-=(const Point &point) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&point);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreSInt2(this, X);
		return *this;
	}

	Point &Point::operator*=(const Point &point) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&point);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreSInt2(this, X);
		return *this;
	}

	Point &Point::operator*=(int value) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR X = XMVectorScale(v1, value);
		XMStoreSInt2(this, X);
		return *this;
	}

	Point &Point::operator/=(int value) noexcept
	{
		using namespace DirectX;
		assert(value != 0.0f);
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR X = XMVectorScale(v1, 1.f / value);
		XMStoreSInt2(this, X);
		return *this;
	}

	Point Point::operator+() const noexcept
	{
		return *this;
	}

	Point Point::operator-() const noexcept
	{
		return Point(-x, -y);
	}

	String Point::ToString() const noexcept
	{
		return {"(X:" + std::to_string(x) + ", Y:" + std::to_string(y) + ")"};
	}

	Point operator+(const Point &point1, const Point &point2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point1);
		XMVECTOR v2 = XMLoadSInt2(&point2);
		XMVECTOR X = XMVectorAdd(v1, v2);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Point operator-(const Point &point1, const Point &point2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point1);
		XMVECTOR v2 = XMLoadSInt2(&point2);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Point operator*(const Point &point1, const Point &point2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point1);
		XMVECTOR v2 = XMLoadSInt2(&point2);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Point operator*(const Point &point, int value) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point);
		XMVECTOR X = XMVectorScale(v1, value);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Point operator/(const Point &point1, const Point &point2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point1);
		XMVECTOR v2 = XMLoadSInt2(&point2);
		XMVECTOR X = XMVectorDivide(v1, v2);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Point operator/(const Point &point, int value) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point);
		XMVECTOR X = XMVectorScale(v1, 1.f / value);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Point operator*(int value, const Point &point) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&point);
		XMVECTOR X = XMVectorScale(v1, value);
		Point R;
		XMStoreSInt2(&R, X);
		return R;
	}

	const Point
		Point::Zero(0, 0),
		Point::One(1, 1),
		Point::UnitX(1, 0),
		Point::UnitY(0, 1);
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Point>::operator()(const Pazu::Math::Point &point1, const Pazu::Math::Point &point2) const noexcept
	{
		return ((point1.x < point2.x) || ((point1.x == point2.x) && (point1.y < point2.y)));
	}
} // namespace std

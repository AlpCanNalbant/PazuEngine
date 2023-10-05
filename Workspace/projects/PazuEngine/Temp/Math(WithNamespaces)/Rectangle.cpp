// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

//-------------------------------------------------------------------------------------
// SimpleMath.inl -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------

#include <functional>
#include "Vector2.h"
#include "Rectangle.h"

namespace Pazu::Math
{
	bool Rectangle::operator==(const Rectangle &r) const noexcept
	{
		return (x == r.x) && (y == r.y) && (width == r.width) && (height == r.height);
	}

	bool Rectangle::operator!=(const Rectangle &r) const noexcept
	{
		return (x != r.x) || (y != r.y) || (width != r.width) || (height != r.height);
	}

	Vector2 Rectangle::Location() const noexcept
	{
		return Vector2(float(x), float(y));
	}

	Vector2 Rectangle::Center() const noexcept
	{
		return Vector2(float(x) + (float(width) / 2.f), float(y) + (float(height) / 2.f));
	}

	bool Rectangle::Empty() const noexcept
	{
		return (width == 0 && height == 0 && x == 0 && y == 0);
	}

	bool Rectangle::Contains(long ix, long iy) const noexcept
	{
		return (x <= ix) && (ix < (x + width)) && (y <= iy) && (iy < (y + height));
	}

	bool Rectangle::Contains(const Rectangle &r) const noexcept
	{
		return (x <= r.x) && ((r.x + r.width) <= (x + width)) && (y <= r.y) && ((r.y + r.height) <= (y + height));
	}

	bool Rectangle::Contains(const Vector2 &point) const noexcept
	{
		return (float(x) <= point.x) && (point.x < float(x + width)) && (float(y) <= point.y) && (point.y < float(y + height));
	}

	void Rectangle::Inflate(long horizAmount, long vertAmount) noexcept
	{
		x -= horizAmount;
		y -= vertAmount;
		width += horizAmount;
		height += vertAmount;
	}

	bool Rectangle::Intersects(const Rectangle &r) const noexcept
	{
		return (r.x < (x + width)) && (x < (r.x + r.width)) && (r.y < (y + height)) && (y < (r.y + r.height));
	}

	void Rectangle::Offset(long ox, long oy) noexcept
	{
		x += ox;
		y += oy;
	}

	Rectangle Rectangle::Intersect(const Rectangle &ra, const Rectangle &rb) noexcept
	{
		long righta = ra.x + ra.width;
		long rightb = rb.x + rb.width;

		long bottoma = ra.y + ra.height;
		long bottomb = rb.y + rb.height;

		long maxX = ra.x > rb.x ? ra.x : rb.x;
		long maxY = ra.y > rb.y ? ra.y : rb.y;

		long minRight = righta < rightb ? righta : rightb;
		long minBottom = bottoma < bottomb ? bottoma : bottomb;

		Rectangle result;
		if ((minRight > maxX) && (minBottom > maxY))
		{
			result.x = maxX;
			result.y = maxY;
			result.width = minRight - maxX;
			result.height = minBottom - maxY;
		}
		else
		{
			result.x = 0;
			result.y = 0;
			result.width = 0;
			result.height = 0;
		}

		return result;
	}

	Rectangle Rectangle::Union(const Rectangle &ra, const Rectangle &rb) noexcept
	{
		long righta = ra.x + ra.width;
		long rightb = rb.x + rb.width;

		long bottoma = ra.y + ra.height;
		long bottomb = rb.y + rb.height;

		int minX = ra.x < rb.x ? ra.x : rb.x;
		int minY = ra.y < rb.y ? ra.y : rb.y;

		int maxRight = righta > rightb ? righta : rightb;
		int maxBottom = bottoma > bottomb ? bottoma : bottomb;

		Rectangle result;
		result.x = minX;
		result.y = minY;
		result.width = maxRight - minX;
		result.height = maxBottom - minY;
		return result;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Rectangle>::operator()(const Pazu::Math::Rectangle &r1, const Pazu::Math::Rectangle &r2) const noexcept
	{
		return ((r1.x < r2.x) || ((r1.x == r2.x) && (r1.y < r2.y)) || ((r1.x == r2.x) && (r1.y == r2.y) && (r1.width < r2.width)) || ((r1.x == r2.x) && (r1.y == r2.y) && (r1.width == r2.width) && (r1.height < r2.height)));
	}
} // namespace std

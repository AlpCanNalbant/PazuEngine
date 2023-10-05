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

namespace Pazu
{
	constexpr Point::Point(int value)
		: XMINT2(value, value) {}

	constexpr Point::Point(int x, int y)
		: XMINT2(x, y) {}

	constexpr bool Point::Empty() const
	{
		return ((x == 0) && (y == 0));
	}
} // namespace Pazu

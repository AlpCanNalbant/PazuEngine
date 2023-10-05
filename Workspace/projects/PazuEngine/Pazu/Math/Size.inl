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
	constexpr Size::Size(unsigned int value)
		: XMUINT2(value, value) {}

	constexpr Size::Size(unsigned int width, unsigned int height)
		: XMUINT2(width, height) {}

	constexpr bool Size::Empty() const
	{
		return ((x == 0) && (y == 0));
	}

	constexpr unsigned int Size::Width() const
	{
		return x;
	}

	constexpr void Size::Width(const unsigned int w)
	{
		x = w;
	}

	constexpr unsigned int Size::Height() const
	{
		return y;
	}

	constexpr void Size::Height(const unsigned int h)
	{
		y = h;
	}
} // namespace Pazu

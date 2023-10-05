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

namespace Pazu::Math
{
	constexpr Size::Size(int value) noexcept
		: XMINT2(value, value) {}

	constexpr Size::Size(int width, int height) noexcept
		: XMINT2(width, height) {}

	constexpr bool Size::Empty() const noexcept
	{
		return ((x == 0) && (y == 0));
	}

	constexpr int32_t Size::Width() const noexcept
	{
		return x;
	}

	constexpr void Size::Width(const int32_t w) noexcept
	{
		x = w;
	}

	constexpr int32_t Size::Height() const noexcept
	{
		return y;
	}

	constexpr void Size::Height(const int32_t h) noexcept
	{
		y = h;
	}
} // namespace Pazu

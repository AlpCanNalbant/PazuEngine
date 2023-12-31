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
	constexpr Color::Color(float _r, float _g, float _b) noexcept
		: XMFLOAT4(_r, _g, _b, 1.f) {}

	constexpr Color::Color(float _r, float _g, float _b, float _a) noexcept
		: XMFLOAT4(_r, _g, _b, _a) {}
} // namespace Pazu

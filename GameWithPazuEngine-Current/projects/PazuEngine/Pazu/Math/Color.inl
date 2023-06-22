//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
namespace Pazu
{
	constexpr Color::Color(float _r, float _g, float _b)
			: XMFLOAT4(_r, _g, _b, 1.f) {}

	constexpr Color::Color(float _r, float _g, float _b, float _a)
			: XMFLOAT4(_r, _g, _b, _a) {}
} // namespace Pazu

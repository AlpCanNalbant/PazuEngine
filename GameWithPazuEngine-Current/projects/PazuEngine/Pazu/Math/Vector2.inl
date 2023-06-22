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
	constexpr Vector2::Vector2(float ix)
			: XMFLOAT2(ix, ix) {}

	constexpr Vector2::Vector2(float ix, float iy)
			: XMFLOAT2(ix, iy) {}
} // namespace Pazu

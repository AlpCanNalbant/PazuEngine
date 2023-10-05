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
	constexpr Vector4::Vector4(float ix)
		: XMFLOAT4(ix, ix, ix, ix) {}

	constexpr Vector4::Vector4(float ix, float iy, float iz, float iw)
		: XMFLOAT4(ix, iy, iz, iw) {}
} // namespace Pazu

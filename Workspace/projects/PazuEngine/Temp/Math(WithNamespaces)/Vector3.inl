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
	constexpr Vector3::Vector3(float ix) noexcept
		: XMFLOAT3(ix, ix, ix) {}

	constexpr Vector3::Vector3(float ix, float iy, float iz) noexcept
		: XMFLOAT3(ix, iy, iz) {}
} // namespace Pazu

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
	constexpr Vector3::Vector3(float ix)
			: XMFLOAT3(ix, ix, ix) {}

	constexpr Vector3::Vector3(float ix, float iy, float iz)
			: XMFLOAT3(ix, iy, iz) {}
} // namespace Pazu

//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
namespace Pazu::Math
{
	constexpr Viewport::Viewport(float ix, float iy, float iw, float ih, float iminz, float imaxz) noexcept
			: x(ix), y(iy), width(iw), height(ih), minDepth(iminz), maxDepth(imaxz) {}
} // namespace Pazu

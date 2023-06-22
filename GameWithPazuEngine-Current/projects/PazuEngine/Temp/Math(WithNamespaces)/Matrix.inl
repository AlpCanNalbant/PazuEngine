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
	constexpr Matrix::Matrix(float m00, float m01, float m02, float m03,
													 float m10, float m11, float m12, float m13,
													 float m20, float m21, float m22, float m23,
													 float m30, float m31, float m32, float m33) noexcept
			: XMFLOAT4X4(m00, m01, m02, m03,
									 m10, m11, m12, m13,
									 m20, m21, m22, m23,
									 m30, m31, m32, m33) {}
} // namespace Pazu

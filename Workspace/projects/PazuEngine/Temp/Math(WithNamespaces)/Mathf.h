// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

//-------------------------------------------------------------------------------------
// DirectXMath.h -- SIMD C++ Math library
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkID=615560
//-------------------------------------------------------------------------------------

#pragma once

namespace Pazu::Math
{
	class Mathf
	{
	public:
		Mathf() = delete;
		static constexpr float ToRadians(const float degrees) noexcept;
		static constexpr float ToDegrees(const float radians) noexcept;

		static constexpr float
			Pi{3.141592654f},
			TwoPi{6.283185307f},
			PiOver2{1.570796327f},
			PiOver4{0.785398163f};
	};
} // namespace Pazu
#include "Mathf.inl"

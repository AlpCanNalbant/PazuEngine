//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
// DirectXColors.h -- C++ Color Math library
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkID=615560
//-------------------------------------------------------------------------------------
#pragma once
#include <XMath/DirectXPackedVector.h>

namespace Pazu::Math
{
	struct Vector3;
	struct Vector4;

	struct Color : public DirectX::XMFLOAT4
	{
		Color() noexcept;
		constexpr Color(float _r, float _g, float _b) noexcept;
		constexpr Color(float _r, float _g, float _b, float _a) noexcept;
		explicit Color(const Vector3 &clr) noexcept;
		explicit Color(const Vector4 &clr) noexcept;
		explicit Color(_In_reads_(4) const float *pArray) noexcept;
		Color(DirectX::FXMVECTOR V) noexcept;
		Color(const XMFLOAT4 &c) noexcept;
		explicit Color(const DirectX::XMVECTORF32 &F) noexcept;
		explicit Color(const DirectX::PackedVector::XMCOLOR &Packed) noexcept;	 // BGRA Direct3D 9 D3DCOLOR packed color
		explicit Color(const DirectX::PackedVector::XMUBYTEN4 &Packed) noexcept; // RGBA XNA Game Studio packed color
		Color(const Color &) = default;
		Color &operator=(const Color &) = default;
		Color(Color &&) = default;
		Color &operator=(Color &&) = default;
		operator DirectX::XMVECTOR() const noexcept;
		operator const float *() const noexcept;
		bool operator==(const Color &c) const noexcept;
		bool operator!=(const Color &c) const noexcept;
		Color &operator=(const DirectX::XMVECTORF32 &F) noexcept;
		Color &operator=(const DirectX::PackedVector::XMCOLOR &Packed) noexcept;
		Color &operator=(const DirectX::PackedVector::XMUBYTEN4 &Packed) noexcept;
		Color &operator+=(const Color &c) noexcept;
		Color &operator-=(const Color &c) noexcept;
		Color &operator*=(const Color &c) noexcept;
		Color &operator*=(float S) noexcept;
		Color &operator/=(const Color &c) noexcept;
		Color operator+() const noexcept;
		Color operator-() const noexcept;
		float R() const noexcept;
		void R(float r) noexcept;
		float G() const noexcept;
		void G(float g) noexcept;
		float B() const noexcept;
		void B(float b) noexcept;
		float A() const noexcept;
		void A(float a) noexcept;
		DirectX::PackedVector::XMCOLOR BGRA() const noexcept;
		DirectX::PackedVector::XMUBYTEN4 RGBA() const noexcept;
		Vector3 ToVector3() const noexcept;
		Vector4 ToVector4() const noexcept;
		void Negate() noexcept;
		void Negate(Color &result) const noexcept;
		void Saturate() noexcept;
		void Saturate(Color &result) const noexcept;
		void Premultiply() noexcept;
		void Premultiply(Color &result) const noexcept;
		void AdjustSaturation(float sat) noexcept;
		void AdjustSaturation(float sat, Color &result) const noexcept;
		void AdjustContrast(float contrast) noexcept;
		void AdjustContrast(float contrast, Color &result) const noexcept;
		static void Modulate(const Color &c1, const Color &c2, Color &result) noexcept;
		static Color Modulate(const Color &c1, const Color &c2) noexcept;
		static void Lerp(const Color &c1, const Color &c2, float t, Color &result) noexcept;
		static Color Lerp(const Color &c1, const Color &c2, float t) noexcept;

		static const Color
				AliceBlue,
				AntiqueWhite,
				Aqua,
				Aquamarine,
				Azure,
				Beige,
				Bisque,
				Black,
				BlanchedAlmond,
				Blue,
				BlueViolet,
				Brown,
				BurlyWood,
				CadetBlue,
				Chartreuse,
				Chocolate,
				Coral,
				CornflowerBlue,
				Cornsilk,
				Crimson,
				Cyan,
				DarkBlue,
				DarkCyan,
				DarkGoldenrod,
				DarkGray,
				DarkGreen,
				DarkKhaki,
				DarkMagenta,
				DarkOliveGreen,
				DarkOrange,
				DarkOrchid,
				DarkRed,
				DarkSalmon,
				DarkSeaGreen,
				DarkSlateBlue,
				DarkSlateGray,
				DarkTurquoise,
				DarkViolet,
				DeepPink,
				DeepSkyBlue,
				DimGray,
				DodgerBlue,
				Firebrick,
				FloralWhite,
				ForestGreen,
				Fuchsia,
				Gainsboro,
				GhostWhite,
				Gold,
				Goldenrod,
				Gray,
				Green,
				GreenYellow,
				Honeydew,
				HotPink,
				IndianRed,
				Indigo,
				Ivory,
				Khaki,
				Lavender,
				LavenderBlush,
				LawnGreen,
				LemonChiffon,
				LightBlue,
				LightCoral,
				LightCyan,
				LightGoldenrodYellow,
				LightGreen,
				LightGray,
				LightPink,
				LightSalmon,
				LightSeaGreen,
				LightSkyBlue,
				LightSlateGray,
				LightSteelBlue,
				LightYellow,
				Lime,
				LimeGreen,
				Linen,
				Magenta,
				Maroon,
				MediumAquamarine,
				MediumBlue,
				MediumOrchid,
				MediumPurple,
				MediumSeaGreen,
				MediumSlateBlue,
				MediumSpringGreen,
				MediumTurquoise,
				MediumVioletRed,
				MidnightBlue,
				MintCream,
				MistyRose,
				Moccasin,
				NavajoWhite,
				Navy,
				OldLace,
				Olive,
				OliveDrab,
				Orange,
				OrangeRed,
				Orchid,
				PaleGoldenrod,
				PaleGreen,
				PaleTurquoise,
				PaleVioletRed,
				PapayaWhip,
				PeachPuff,
				Peru,
				Pink,
				Plum,
				PowderBlue,
				Purple,
				Red,
				RosyBrown,
				RoyalBlue,
				SaddleBrown,
				Salmon,
				SandyBrown,
				SeaGreen,
				SeaShell,
				Sienna,
				Silver,
				SkyBlue,
				SlateBlue,
				SlateGray,
				Snow,
				SpringGreen,
				SteelBlue,
				Tan,
				Teal,
				Thistle,
				Tomato,
				Transparent,
				Turquoise,
				Violet,
				Wheat,
				White,
				WhiteSmoke,
				Yellow,
				YellowGreen;
	};

	Color operator+(const Color &C1, const Color &C2) noexcept;
	Color operator-(const Color &C1, const Color &C2) noexcept;
	Color operator*(const Color &C1, const Color &C2) noexcept;
	Color operator*(const Color &C, float S) noexcept;
	Color operator/(const Color &C1, const Color &C2) noexcept;
	Color operator*(float S, const Color &C) noexcept;
} // namespace Pazu
#include "Color.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Color>
	{
		bool operator()(const Pazu::Math::Color &C1, const Pazu::Math::Color &C2) const noexcept;
	};
} // namespace std

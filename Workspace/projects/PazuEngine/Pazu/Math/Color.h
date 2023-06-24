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

namespace Pazu
{
	struct Vector3;
	struct Vector4;

	struct Color : public DirectX::XMFLOAT4
	{
		Color();
		constexpr Color(float _r, float _g, float _b);
		constexpr Color(float _r, float _g, float _b, float _a);
		explicit Color(const Vector3 &clr);
		explicit Color(const Vector4 &clr);
		explicit Color(_In_reads_(4) const float *pArray);
		Color(DirectX::FXMVECTOR V);
		Color(const XMFLOAT4 &c);
		explicit Color(const DirectX::XMVECTORF32 &F);
		explicit Color(const DirectX::PackedVector::XMCOLOR &Packed);		// BGRA Direct3D 9 D3DCOLOR packed color
		explicit Color(const DirectX::PackedVector::XMUBYTEN4 &Packed); // RGBA XNA Game Studio packed color
		Color(const Color &) = default;
		Color &operator=(const Color &) = default;
		Color(Color &&) = default;
		Color &operator=(Color &&) = default;
		operator DirectX::XMVECTOR() const;
		operator const float *() const;
		bool operator==(const Color &c) const;
		bool operator!=(const Color &c) const;
		Color &operator=(const DirectX::XMVECTORF32 &F);
		Color &operator=(const DirectX::PackedVector::XMCOLOR &Packed);
		Color &operator=(const DirectX::PackedVector::XMUBYTEN4 &Packed);
		Color &operator+=(const Color &c);
		Color &operator-=(const Color &c);
		Color &operator*=(const Color &c);
		Color &operator*=(float S);
		Color &operator/=(const Color &c);
		Color operator+() const;
		Color operator-() const;
		float R() const;
		void R(float r);
		float G() const;
		void G(float g);
		float B() const;
		void B(float b);
		float A() const;
		void A(float a);
		DirectX::PackedVector::XMCOLOR BGRA() const;
		DirectX::PackedVector::XMUBYTEN4 RGBA() const;
		Vector3 ToVector3() const;
		Vector4 ToVector4() const;
		void Negate();
		void Negate(Color &result) const;
		void Saturate();
		void Saturate(Color &result) const;
		void Premultiply();
		void Premultiply(Color &result) const;
		void AdjustSaturation(float sat);
		void AdjustSaturation(float sat, Color &result) const;
		void AdjustContrast(float contrast);
		void AdjustContrast(float contrast, Color &result) const;
		static void Modulate(const Color &c1, const Color &c2, Color &result);
		static Color Modulate(const Color &c1, const Color &c2);
		static void Lerp(const Color &c1, const Color &c2, float t, Color &result);
		static Color Lerp(const Color &c1, const Color &c2, float t);

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

	Color operator+(const Color &C1, const Color &C2);
	Color operator-(const Color &C1, const Color &C2);
	Color operator*(const Color &C1, const Color &C2);
	Color operator*(const Color &C, float S);
	Color operator/(const Color &C1, const Color &C2);
	Color operator*(float S, const Color &C);
} // namespace Pazu
#include "Color.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Color>
	{
		bool operator()(const Pazu::Color &C1, const Pazu::Color &C2) const;
	};
} // namespace std

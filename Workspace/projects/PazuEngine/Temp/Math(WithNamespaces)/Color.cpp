//-------------------------------------------------------------------------------------
// SimpleMath.inl -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
#include <functional>
#include <XMath/DirectXPackedVector.h>
#include "Vector3.h"
#include "Vector4.h"
#include "Color.h"

namespace Pazu::Math
{
	Color::Color() noexcept
			: XMFLOAT4(0.f, 0.f, 0.f, 1.f) {}

	Color::Color(const Vector3 &clr) noexcept
			: XMFLOAT4(clr.x, clr.y, clr.z, 1.f) {}

	Color::Color(const Vector4 &clr) noexcept
			: XMFLOAT4(clr.x, clr.y, clr.z, clr.w) {}

	Color::Color(_In_reads_(4) const float *pArray) noexcept
			: XMFLOAT4(pArray) {}

	Color::Color(DirectX::FXMVECTOR V) noexcept
	{
		XMStoreFloat4(this, V);
	}

	Color::Color(const XMFLOAT4 &c) noexcept
	{
		this->x = c.x;
		this->y = c.y;
		this->z = c.z;
		this->w = c.w;
	}

	Color::Color(const DirectX::XMVECTORF32 &F) noexcept
	{
		this->x = F.f[0];
		this->y = F.f[1];
		this->z = F.f[2];
		this->w = F.f[3];
	}

	Color::Color(const DirectX::PackedVector::XMCOLOR &Packed) noexcept
	{
		using namespace DirectX;
		XMStoreFloat4(this, PackedVector::XMLoadColor(&Packed));
	}

	Color::Color(const DirectX::PackedVector::XMUBYTEN4 &Packed) noexcept
	{
		using namespace DirectX;
		XMStoreFloat4(this, PackedVector::XMLoadUByteN4(&Packed));
	}

	Color::operator DirectX::XMVECTOR() const noexcept
	{
		return XMLoadFloat4(this);
	}

	Color::operator const float *() const noexcept
	{
		return reinterpret_cast<const float *>(this);
	}

	bool Color::operator==(const Color &c) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(this);
		XMVECTOR c2 = XMLoadFloat4(&c);
		return XMColorEqual(c1, c2);
	}

	bool Color::operator!=(const Color &c) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(this);
		XMVECTOR c2 = XMLoadFloat4(&c);
		return XMColorNotEqual(c1, c2);
	}

	Color &Color::operator=(const DirectX::XMVECTORF32 &F) noexcept
	{
		x = F.f[0];
		y = F.f[1];
		z = F.f[2];
		w = F.f[3];
		return *this;
	}

	Color &Color::operator=(const DirectX::PackedVector::XMCOLOR &Packed) noexcept
	{
		using namespace DirectX;
		XMStoreFloat4(this, PackedVector::XMLoadColor(&Packed));
		return *this;
	}

	Color &Color::operator=(const DirectX::PackedVector::XMUBYTEN4 &Packed) noexcept
	{
		using namespace DirectX;
		XMStoreFloat4(this, PackedVector::XMLoadUByteN4(&Packed));
		return *this;
	}

	Color &Color::operator+=(const Color &c) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(this);
		XMVECTOR c2 = XMLoadFloat4(&c);
		XMStoreFloat4(this, XMVectorAdd(c1, c2));
		return *this;
	}

	Color &Color::operator-=(const Color &c) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(this);
		XMVECTOR c2 = XMLoadFloat4(&c);
		XMStoreFloat4(this, XMVectorSubtract(c1, c2));
		return *this;
	}

	Color &Color::operator*=(const Color &c) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(this);
		XMVECTOR c2 = XMLoadFloat4(&c);
		XMStoreFloat4(this, XMVectorMultiply(c1, c2));
		return *this;
	}

	Color &Color::operator*=(float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(this, XMVectorScale(c, S));
		return *this;
	}

	Color &Color::operator/=(const Color &c) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(this);
		XMVECTOR c2 = XMLoadFloat4(&c);
		XMStoreFloat4(this, XMVectorDivide(c1, c2));
		return *this;
	}

	Color Color::operator+() const noexcept
	{
		return *this;
	}

	Color Color::operator-() const noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		Color R;
		XMStoreFloat4(&R, XMVectorNegate(c));
		return R;
	}

	float Color::R() const noexcept
	{
		return x;
	}

	void Color::R(float r) noexcept
	{
		x = r;
	}

	float Color::G() const noexcept
	{
		return y;
	}

	void Color::G(float g) noexcept
	{
		y = g;
	}

	float Color::B() const noexcept
	{
		return z;
	}

	void Color::B(float b) noexcept
	{
		z = b;
	}

	float Color::A() const noexcept
	{
		return w;
	}

	void Color::A(float a) noexcept
	{
		w = a;
	}

	DirectX::PackedVector::XMCOLOR Color::BGRA() const noexcept
	{
		using namespace DirectX;
		XMVECTOR clr = XMLoadFloat4(this);
		PackedVector::XMCOLOR Packed;
		PackedVector::XMStoreColor(&Packed, clr);
		return Packed;
	}

	DirectX::PackedVector::XMUBYTEN4 Color::RGBA() const noexcept
	{
		using namespace DirectX;
		XMVECTOR clr = XMLoadFloat4(this);
		PackedVector::XMUBYTEN4 Packed;
		PackedVector::XMStoreUByteN4(&Packed, clr);
		return Packed;
	}

	Vector3 Color::ToVector3() const noexcept
	{
		return Vector3(x, y, z);
	}

	Vector4 Color::ToVector4() const noexcept
	{
		return Vector4(x, y, z, w);
	}

	void Color::Negate() noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(this, XMColorNegative(c));
	}

	void Color::Negate(Color &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMColorNegative(c));
	}

	void Color::Saturate() noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(this, XMVectorSaturate(c));
	}

	void Color::Saturate(Color &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMVectorSaturate(c));
	}

	void Color::Premultiply() noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMVECTOR a = XMVectorSplatW(c);
		a = XMVectorSelect(g_XMIdentityR3, a, g_XMSelect1110);
		XMStoreFloat4(this, XMVectorMultiply(c, a));
	}

	void Color::Premultiply(Color &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMVECTOR a = XMVectorSplatW(c);
		a = XMVectorSelect(g_XMIdentityR3, a, g_XMSelect1110);
		XMStoreFloat4(&result, XMVectorMultiply(c, a));
	}

	void Color::AdjustSaturation(float sat) noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(this, XMColorAdjustSaturation(c, sat));
	}

	void Color::AdjustSaturation(float sat, Color &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMColorAdjustSaturation(c, sat));
	}

	void Color::AdjustContrast(float contrast) noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(this, XMColorAdjustContrast(c, contrast));
	}

	void Color::AdjustContrast(float contrast, Color &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMColorAdjustContrast(c, contrast));
	}

	void Color::Modulate(const Color &c1, const Color &c2, Color &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR C0 = XMLoadFloat4(&c1);
		XMVECTOR C1 = XMLoadFloat4(&c2);
		XMStoreFloat4(&result, XMColorModulate(C0, C1));
	}

	Color Color::Modulate(const Color &c1, const Color &c2) noexcept
	{
		using namespace DirectX;
		XMVECTOR C0 = XMLoadFloat4(&c1);
		XMVECTOR C1 = XMLoadFloat4(&c2);

		Color result;
		XMStoreFloat4(&result, XMColorModulate(C0, C1));
		return result;
	}

	void Color::Lerp(const Color &c1, const Color &c2, float t, Color &result) noexcept
	{
		using namespace DirectX;
		XMVECTOR C0 = XMLoadFloat4(&c1);
		XMVECTOR C1 = XMLoadFloat4(&c2);
		XMStoreFloat4(&result, XMVectorLerp(C0, C1, t));
	}

	Color Color::Lerp(const Color &c1, const Color &c2, float t) noexcept
	{
		using namespace DirectX;
		XMVECTOR C0 = XMLoadFloat4(&c1);
		XMVECTOR C1 = XMLoadFloat4(&c2);

		Color result;
		XMStoreFloat4(&result, XMVectorLerp(C0, C1, t));
		return result;
	}

	const Color
			Color::AliceBlue(0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f),
			Color::AntiqueWhite(0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f),
			Color::Aqua(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f),
			Color::Aquamarine(0.498039246f, 1.000000000f, 0.831372619f, 1.000000000f),
			Color::Azure(0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f),
			Color::Beige(0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f),
			Color::Bisque(1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f),
			Color::Black(0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f),
			Color::BlanchedAlmond(1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f),
			Color::Blue(0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f),
			Color::BlueViolet(0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f),
			Color::Brown(0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f),
			Color::BurlyWood(0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f),
			Color::CadetBlue(0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f),
			Color::Chartreuse(0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f),
			Color::Chocolate(0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f),
			Color::Coral(1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f),
			Color::CornflowerBlue(0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f),
			Color::Cornsilk(1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f),
			Color::Crimson(0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f),
			Color::Cyan(0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f),
			Color::DarkBlue(0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f),
			Color::DarkCyan(0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f),
			Color::DarkGoldenrod(0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f),
			Color::DarkGray(0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f),
			Color::DarkGreen(0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f),
			Color::DarkKhaki(0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f),
			Color::DarkMagenta(0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f),
			Color::DarkOliveGreen(0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f),
			Color::DarkOrange(1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f),
			Color::DarkOrchid(0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f),
			Color::DarkRed(0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f),
			Color::DarkSalmon(0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f),
			Color::DarkSeaGreen(0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f),
			Color::DarkSlateBlue(0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f),
			Color::DarkSlateGray(0.184313729f, 0.309803933f, 0.309803933f, 1.000000000f),
			Color::DarkTurquoise(0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f),
			Color::DarkViolet(0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f),
			Color::DeepPink(1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f),
			Color::DeepSkyBlue(0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f),
			Color::DimGray(0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f),
			Color::DodgerBlue(0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f),
			Color::Firebrick(0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f),
			Color::FloralWhite(1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f),
			Color::ForestGreen(0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f),
			Color::Fuchsia(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f),
			Color::Gainsboro(0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f),
			Color::GhostWhite(0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f),
			Color::Gold(1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f),
			Color::Goldenrod(0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f),
			Color::Gray(0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f),
			Color::Green(0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f),
			Color::GreenYellow(0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f),
			Color::Honeydew(0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f),
			Color::HotPink(1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f),
			Color::IndianRed(0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f),
			Color::Indigo(0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f),
			Color::Ivory(1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f),
			Color::Khaki(0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f),
			Color::Lavender(0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f),
			Color::LavenderBlush(1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f),
			Color::LawnGreen(0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f),
			Color::LemonChiffon(1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f),
			Color::LightBlue(0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f),
			Color::LightCoral(0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f),
			Color::LightCyan(0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f),
			Color::LightGoldenrodYellow(0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f),
			Color::LightGreen(0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f),
			Color::LightGray(0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f),
			Color::LightPink(1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f),
			Color::LightSalmon(1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f),
			Color::LightSeaGreen(0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f),
			Color::LightSkyBlue(0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f),
			Color::LightSlateGray(0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f),
			Color::LightSteelBlue(0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f),
			Color::LightYellow(1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f),
			Color::Lime(0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f),
			Color::LimeGreen(0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f),
			Color::Linen(0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f),
			Color::Magenta(1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f),
			Color::Maroon(0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f),
			Color::MediumAquamarine(0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f),
			Color::MediumBlue(0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f),
			Color::MediumOrchid(0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f),
			Color::MediumPurple(0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f),
			Color::MediumSeaGreen(0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f),
			Color::MediumSlateBlue(0.482352972f, 0.407843173f, 0.933333397f, 1.000000000f),
			Color::MediumSpringGreen(0.000000000f, 0.980392218f, 0.603921592f, 1.000000000f),
			Color::MediumTurquoise(0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f),
			Color::MediumVioletRed(0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f),
			Color::MidnightBlue(0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f),
			Color::MintCream(0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f),
			Color::MistyRose(1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f),
			Color::Moccasin(1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f),
			Color::NavajoWhite(1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f),
			Color::Navy(0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f),
			Color::OldLace(0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f),
			Color::Olive(0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f),
			Color::OliveDrab(0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f),
			Color::Orange(1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f),
			Color::OrangeRed(1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f),
			Color::Orchid(0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f),
			Color::PaleGoldenrod(0.933333397f, 0.909803987f, 0.666666687f, 1.000000000f),
			Color::PaleGreen(0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f),
			Color::PaleTurquoise(0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f),
			Color::PaleVioletRed(0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f),
			Color::PapayaWhip(1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f),
			Color::PeachPuff(1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f),
			Color::Peru(0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f),
			Color::Pink(1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f),
			Color::Plum(0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f),
			Color::PowderBlue(0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f),
			Color::Purple(0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f),
			Color::Red(1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f),
			Color::RosyBrown(0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f),
			Color::RoyalBlue(0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f),
			Color::SaddleBrown(0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f),
			Color::Salmon(0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f),
			Color::SandyBrown(0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f),
			Color::SeaGreen(0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f),
			Color::SeaShell(1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f),
			Color::Sienna(0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f),
			Color::Silver(0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f),
			Color::SkyBlue(0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f),
			Color::SlateBlue(0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f),
			Color::SlateGray(0.439215720f, 0.501960814f, 0.564705908f, 1.000000000f),
			Color::Snow(1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f),
			Color::SpringGreen(0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f),
			Color::SteelBlue(0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f),
			Color::Tan(0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f),
			Color::Teal(0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f),
			Color::Thistle(0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f),
			Color::Tomato(1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f),
			Color::Transparent(0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f),
			Color::Turquoise(0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f),
			Color::Violet(0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f),
			Color::Wheat(0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f),
			Color::White(1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f),
			Color::WhiteSmoke(0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f),
			Color::Yellow(1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f),
			Color::YellowGreen(0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f);

	Color operator+(const Color &C1, const Color &C2) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(&C1);
		XMVECTOR c2 = XMLoadFloat4(&C2);
		Color R;
		XMStoreFloat4(&R, XMVectorAdd(c1, c2));
		return R;
	}

	Color operator-(const Color &C1, const Color &C2) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(&C1);
		XMVECTOR c2 = XMLoadFloat4(&C2);
		Color R;
		XMStoreFloat4(&R, XMVectorSubtract(c1, c2));
		return R;
	}

	Color operator*(const Color &C1, const Color &C2) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(&C1);
		XMVECTOR c2 = XMLoadFloat4(&C2);
		Color R;
		XMStoreFloat4(&R, XMVectorMultiply(c1, c2));
		return R;
	}

	Color operator*(const Color &C, float S) noexcept
	{
		using namespace DirectX;
		XMVECTOR c = XMLoadFloat4(&C);
		Color R;
		XMStoreFloat4(&R, XMVectorScale(c, S));
		return R;
	}

	Color operator/(const Color &C1, const Color &C2) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(&C1);
		XMVECTOR c2 = XMLoadFloat4(&C2);
		Color R;
		XMStoreFloat4(&R, XMVectorDivide(c1, c2));
		return R;
	}

	Color operator*(float S, const Color &C) noexcept
	{
		using namespace DirectX;
		XMVECTOR c1 = XMLoadFloat4(&C);
		Color R;
		XMStoreFloat4(&R, XMVectorScale(c1, S));
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Color>::operator()(const Pazu::Math::Color &C1, const Pazu::Math::Color &C2) const noexcept
	{
		return ((C1.x < C2.x) || ((C1.x == C2.x) && (C1.y < C2.y)) || ((C1.x == C2.x) && (C1.y == C2.y) && (C1.z < C2.z)) || ((C1.x == C2.x) && (C1.y == C2.y) && (C1.z == C2.z) && (C1.w < C2.w)));
	}
} // namespace std

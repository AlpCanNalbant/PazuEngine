// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include <functional>
#include "Size.h"

namespace Pazu::Math
{
	Size::Size() noexcept
		: XMINT2(0, 0) {}

	Size::Size(_In_reads_(2) const int *array) noexcept
		: XMINT2(array) {}

	Size::Size(DirectX::FXMVECTOR xmVector) noexcept
	{
		XMStoreSInt2(this, xmVector);
	}

	Size::Size(const XMINT2 &xmInt32) noexcept
	{
		this->x = xmInt32.x;
		this->y = xmInt32.y;
	}

	Size::Size(const DirectX::XMVECTORI32 &xmVectorI32) noexcept
	{
		this->x = xmVectorI32.i[0];
		this->y = xmVectorI32.i[1];
	}

	Size::operator DirectX::XMVECTOR() const noexcept
	{
		return XMLoadSInt2(this);
	}

	bool Size::operator==(const Size &size) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&size);
		return XMVector2Equal(v1, v2);
	}

	bool Size::operator!=(const Size &size) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&size);
		return XMVector2NotEqual(v1, v2);
	}

	Size &Size::operator=(const DirectX::XMVECTORI32 &xmVectorI32) noexcept
	{
		x = xmVectorI32.i[0];
		y = xmVectorI32.i[1];
		return *this;
	}

	Size &Size::operator+=(const Size &size) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&size);
		XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreSInt2(this, X);
		return *this;
	}

	Size &Size::operator-=(const Size &size) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&size);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreSInt2(this, X);
		return *this;
	}

	Size &Size::operator*=(const Size &size) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR v2 = XMLoadSInt2(&size);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreSInt2(this, X);
		return *this;
	}

	Size &Size::operator*=(int value) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR X = XMVectorScale(v1, value);
		XMStoreSInt2(this, X);
		return *this;
	}

	Size &Size::operator/=(int value) noexcept
	{
		using namespace DirectX;
		assert(value != 0.0f);
		XMVECTOR v1 = XMLoadSInt2(this);
		XMVECTOR X = XMVectorScale(v1, 1.f / value);
		XMStoreSInt2(this, X);
		return *this;
	}

	Size Size::operator+() const noexcept
	{
		return *this;
	}

	Size Size::operator-() const noexcept
	{
		return Size(-x, -y);
	}

	String Size::ToString() const noexcept
	{
		return {"(Width:" + std::to_string(x) + ", Height:" + std::to_string(y) + ")"};
	}

	const Size
		Size::Zero(0, 0),
		Size::One(1, 1),
		Size::UnitX(1, 0),
		Size::UnitY(0, 1);

	Size operator+(const Size &size1, const Size &size2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size1);
		XMVECTOR v2 = XMLoadSInt2(&size2);
		XMVECTOR X = XMVectorAdd(v1, v2);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Size operator-(const Size &size1, const Size &size2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size1);
		XMVECTOR v2 = XMLoadSInt2(&size2);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Size operator*(const Size &size1, const Size &size2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size1);
		XMVECTOR v2 = XMLoadSInt2(&size2);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Size operator*(const Size &size, int value) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size);
		XMVECTOR X = XMVectorScale(v1, value);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Size operator/(const Size &size1, const Size &size2) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size1);
		XMVECTOR v2 = XMLoadSInt2(&size2);
		XMVECTOR X = XMVectorDivide(v1, v2);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Size operator/(const Size &size, int value) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size);
		XMVECTOR X = XMVectorScale(v1, 1.f / value);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}

	Size operator*(int value, const Size &size) noexcept
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadSInt2(&size);
		XMVECTOR X = XMVectorScale(v1, value);
		Size R;
		XMStoreSInt2(&R, X);
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Size>::operator()(const Pazu::Math::Size &size1, const Pazu::Math::Size &size2) const noexcept
	{
		return ((size1.x < size2.x) || ((size1.x == size2.x) && (size1.y < size2.y)));
	}
} // namespace std

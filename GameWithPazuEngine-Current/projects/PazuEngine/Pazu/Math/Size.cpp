#include <functional>
#include "Size.h"

namespace Pazu
{
	Size::Size()
			: XMUINT2(0, 0) {}

	Size::Size(_In_reads_(2) const unsigned int *array)
			: XMUINT2(array) {}

	Size::Size(DirectX::FXMVECTOR xmVector)
	{
		XMStoreUInt2(this, xmVector);
	}

	Size::Size(const XMUINT2 &xmUint2)
	{
		this->x = xmUint2.x;
		this->y = xmUint2.y;
	}

	Size::Size(const DirectX::XMVECTORU32 &xmVectorU32)
	{
		this->x = xmVectorU32.u[0];
		this->y = xmVectorU32.u[1];
	}

	Size::operator DirectX::XMVECTOR() const
	{
		return XMLoadUInt2(this);
	}

	bool Size::operator==(const Size &size) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR v2 = XMLoadUInt2(&size);
		return XMVector2Equal(v1, v2);
	}

	bool Size::operator!=(const Size &size) const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR v2 = XMLoadUInt2(&size);
		return XMVector2NotEqual(v1, v2);
	}

	Size &Size::operator=(const DirectX::XMVECTORU32 &xmVectorU32)
	{
		x = xmVectorU32.u[0];
		y = xmVectorU32.u[1];
		return *this;
	}

	Size &Size::operator+=(const Size &size)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR v2 = XMLoadUInt2(&size);
		XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreUInt2(this, X);
		return *this;
	}

	Size &Size::operator-=(const Size &size)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR v2 = XMLoadUInt2(&size);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreUInt2(this, X);
		return *this;
	}

	Size &Size::operator*=(const Size &size)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR v2 = XMLoadUInt2(&size);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreUInt2(this, X);
		return *this;
	}

	Size &Size::operator*=(unsigned int value)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR X = XMVectorScale(v1, value);
		XMStoreUInt2(this, X);
		return *this;
	}

	Size &Size::operator/=(unsigned int value)
	{
		using namespace DirectX;
		assert(value != 0.0f);
		XMVECTOR v1 = XMLoadUInt2(this);
		XMVECTOR X = XMVectorScale(v1, 1.f / value);
		XMStoreUInt2(this, X);
		return *this;
	}

	Size Size::operator+() const
	{
		return *this;
	}

	Size Size::operator-() const
	{
		return Size(-x, -y);
	}

	std::string Size::ToString() const
	{
		return {"(Width:" + std::to_string(x) + ", Height:" + std::to_string(y) + ")"};
	}

	const Size
			Size::Zero(0, 0),
			Size::One(1, 1),
			Size::UnitX(1, 0),
			Size::UnitY(0, 1);

	Size operator+(const Size &size1, const Size &size2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size1);
		XMVECTOR v2 = XMLoadUInt2(&size2);
		XMVECTOR X = XMVectorAdd(v1, v2);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}

	Size operator-(const Size &size1, const Size &size2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size1);
		XMVECTOR v2 = XMLoadUInt2(&size2);
		XMVECTOR X = XMVectorSubtract(v1, v2);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}

	Size operator*(const Size &size1, const Size &size2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size1);
		XMVECTOR v2 = XMLoadUInt2(&size2);
		XMVECTOR X = XMVectorMultiply(v1, v2);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}

	Size operator*(const Size &size, int value)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size);
		XMVECTOR X = XMVectorScale(v1, value);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}

	Size operator/(const Size &size1, const Size &size2)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size1);
		XMVECTOR v2 = XMLoadUInt2(&size2);
		XMVECTOR X = XMVectorDivide(v1, v2);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}

	Size operator/(const Size &size, int value)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size);
		XMVECTOR X = XMVectorScale(v1, 1.f / value);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}

	Size operator*(int value, const Size &size)
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadUInt2(&size);
		XMVECTOR X = XMVectorScale(v1, value);
		Size R;
		XMStoreUInt2(&R, X);
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Size>::operator()(const Pazu::Size &size1, const Pazu::Size &size2) const
	{
		return ((size1.x < size2.x) || ((size1.x == size2.x) && (size1.y < size2.y)));
	}
} // namespace std

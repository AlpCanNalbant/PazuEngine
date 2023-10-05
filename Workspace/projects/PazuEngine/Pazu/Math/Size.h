// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <XMath/DirectXMath.h>

namespace Pazu
{
	struct Size : public DirectX::XMUINT2
	{
		Size();
		constexpr explicit Size(unsigned int value);
		constexpr Size(unsigned int width, unsigned int height);
		explicit Size(_In_reads_(2) const unsigned int *array);
		Size(DirectX::FXMVECTOR xmVector);
		Size(const XMUINT2 &xmUint2);
		Size(const DirectX::XMVECTORU32 &xmVectorU32);
		Size(const Size &other) = default;
		Size &operator=(const Size &other) = default;
		Size(Size &&temp) = default;
		Size &operator=(Size &&temp) = default;
		operator DirectX::XMVECTOR() const;
		bool operator==(const Size &size) const;
		bool operator!=(const Size &size) const;
		Size &operator=(const DirectX::XMVECTORU32 &xmVectorU32);
		Size &operator+=(const Size &size);
		Size &operator-=(const Size &size);
		Size &operator*=(const Size &size);
		Size &operator*=(unsigned int value);
		Size &operator/=(unsigned int value);
		Size operator+() const;
		Size operator-() const;
		constexpr bool Empty() const;
		std::string ToString() const;
		constexpr unsigned int Width() const;
		constexpr void Width(const unsigned int w);
		constexpr unsigned int Height() const;
		constexpr void Height(const unsigned int h);

		static const Size
			Zero,
			One,
			UnitX,
			UnitY;
	};

	Size operator+(const Size &size1, const Size &size2);
	Size operator-(const Size &size1, const Size &size2);
	Size operator*(const Size &size1, const Size &size2);
	Size operator*(const Size &size, int value);
	Size operator/(const Size &size1, const Size &size2);
	Size operator/(const Size &size, int value);
	Size operator*(int value, const Size &size);
} // namespace Pazu
#include "Size.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Size>
	{
		bool operator()(const Pazu::Size &size1, const Pazu::Size &size2) const;
	};
} // namespace std

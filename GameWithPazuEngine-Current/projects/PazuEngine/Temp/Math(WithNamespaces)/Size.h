#pragma once
#include <string>
#include <XMath/DirectXMath.h>

namespace Pazu::Math
{
	struct Size : public DirectX::XMINT2
	{
		Size() noexcept;
		constexpr explicit Size(int value) noexcept;
		constexpr Size(int width, int height) noexcept;
		explicit Size(_In_reads_(2) const int *array) noexcept;
		Size(DirectX::FXMVECTOR xmVector) noexcept;
		Size(const XMINT2 &xmInt2) noexcept;
		Size(const DirectX::XMVECTORI32 &xmVectorI32) noexcept;
		Size(const Size &other) = default;
		Size &operator=(const Size &other) = default;
		Size(Size &&temp) = default;
		Size &operator=(Size &&temp) = default;
		operator DirectX::XMVECTOR() const noexcept;
		bool operator==(const Size &size) const noexcept;
		bool operator!=(const Size &size) const noexcept;
		Size &operator=(const DirectX::XMVECTORI32 &xmVectorI32) noexcept;
		Size &operator+=(const Size &size) noexcept;
		Size &operator-=(const Size &size) noexcept;
		Size &operator*=(const Size &size) noexcept;
		Size &operator*=(int value) noexcept;
		Size &operator/=(int value) noexcept;
		Size operator+() const noexcept;
		Size operator-() const noexcept;
		constexpr bool Empty() const noexcept;
		String ToString() const noexcept;
		constexpr int32_t Width() const noexcept;
		constexpr void Width(const int32_t w) noexcept;
		constexpr int32_t Height() const noexcept;
		constexpr void Height(const int32_t h) noexcept;

		static const Size
				Zero,
				One,
				UnitX,
				UnitY;
	};

	Size operator+(const Size &size1, const Size &size2) noexcept;
	Size operator-(const Size &size1, const Size &size2) noexcept;
	Size operator*(const Size &size1, const Size &size2) noexcept;
	Size operator*(const Size &size, int value) noexcept;
	Size operator/(const Size &size1, const Size &size2) noexcept;
	Size operator/(const Size &size, int value) noexcept;
	Size operator*(int value, const Size &size) noexcept;
} // namespace Pazu
#include "Size.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Size>
	{
		bool operator()(const Pazu::Math::Size &size1, const Pazu::Math::Size &size2) const noexcept;
	};
} // namespace std

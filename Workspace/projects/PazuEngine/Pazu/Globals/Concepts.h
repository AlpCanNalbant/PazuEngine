// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	template <typename From, typename To>
	concept StaticCastable = requires(From value) {
		static_cast<To>(value);
	};

	template <typename T>
	concept EmptiableRange = std::ranges::range<T> && requires(T &rng) {
		std::ranges::empty(rng);
	};

	template <typename T>
	concept EmplacebleRange = std::ranges::range<T> && requires(T rng) {
		rng.emplace(std::declval<typename T::value_type>());
	};

	template <typename T>
	concept EmplaceBackableRange = std::ranges::range<T> && requires(T rng) {
		rng.emplace_back(std::declval<typename T::value_type>());
	};

	template <typename T>
	concept AnyEmplacebleRange = EmplacebleRange<T> || EmplaceBackableRange<T>;
}

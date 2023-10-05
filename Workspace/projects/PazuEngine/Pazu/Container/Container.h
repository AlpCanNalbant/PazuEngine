// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	template <std::ranges::common_range T>
	class Container
	{
	public:
		Container() = default;
		template <typename TValue>
			requires std::convertible_to<TValue, typename T::value_type>
		Container(std::initializer_list<TValue> init);
		Container(const Container &other) = default;
		Container(Container &&other) = default;
		virtual ~Container() = default;

		template <typename... Types>
		constexpr void Add(Types &&...args)
			requires(AnyEmplacebleRange<T>);
		constexpr void AddRange(const Container &container)
			requires(AnyEmplacebleRange<T>);
		constexpr void AddRange(Container &&container)
			requires(AnyEmplacebleRange<T>);

		[[nodiscard]] constexpr auto GetCount() const
			requires(std::ranges::sized_range<T>);
		[[nodiscard]] constexpr auto GetSCount() const
			requires(std::ranges::sized_range<T>);
		[[nodiscard]] constexpr bool IsEmpty() const
			requires(EmptiableRange<T>);
		constexpr void SetCount(const std::size_t count)
			requires(std::ranges::sized_range<T>);

		[[nodiscard]] constexpr auto begin() const noexcept;
		[[nodiscard]] constexpr auto begin() noexcept;
		[[nodiscard]] constexpr auto end() const noexcept;
		[[nodiscard]] constexpr auto end() noexcept;

		Container &operator=(const Container &other) = default;
		Container &operator=(Container &&other) = default;
		[[nodiscard]] constexpr auto operator<=>(const Container &other) const noexcept = default;

	protected:
		T range_;
	};
}

#include "Container.inl"

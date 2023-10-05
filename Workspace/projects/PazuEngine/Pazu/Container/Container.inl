// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <std::ranges::common_range T>
	template <typename TValue>
		requires std::convertible_to<TValue, typename T::value_type>
	Container<T>::Container(std::initializer_list<TValue> init)
		: range_(init)
	{
	}

	template <std::ranges::common_range T>
	template <typename... Types>
	constexpr void Container<T>::Add(Types &&...args)
		requires(AnyEmplacebleRange<T>)
	{
		if constexpr (EmplacebleRange<T>)
		{
			range_.emplace(std::forward<Types>(args)...);
		}
		else if constexpr (EmplaceBackableRange<T>)
		{
			range_.emplace_back(std::forward<Types>(args)...);
		}
	}

	template <std::ranges::common_range T>
	constexpr void Container<T>::AddRange(const Container &container)
		requires(AnyEmplacebleRange<T>)
	{
		std::ranges::for_each(container.begin(), container.end(), [this](const auto &value)
							  { Add(value); });
	}

	template <std::ranges::common_range T>
	constexpr void Container<T>::AddRange(Container &&container)
		requires(AnyEmplacebleRange<T>)
	{
		std::ranges::for_each(std::move(container), [this](auto &value)
							  { Add(std::move(value);) });
	}

	template <std::ranges::common_range T>
	constexpr auto Container<T>::GetCount() const
		requires(std::ranges::sized_range<T>)
	{
		std::ranges::size(range_);
	}

	template <std::ranges::common_range T>
	constexpr auto Container<T>::GetSCount() const
		requires(std::ranges::sized_range<T>)
	{
		std::ranges::ssize(range_);
	}

	template <std::ranges::common_range T>
	constexpr bool Container<T>::IsEmpty() const
		requires(EmptiableRange<T>)
	{
		std::ranges::empty(range_);
	}

	template <std::ranges::common_range T>
	constexpr void Container<T>::SetCount(const std::size_t count)
		requires(std::ranges::sized_range<T>)
	{
		Container<T>::range_.resize(count);
	}

	template <std::ranges::common_range T>
	constexpr auto Container<T>::begin() const noexcept
	{
		return std::ranges::cbegin(range_);
	}

	template <std::ranges::common_range T>
	constexpr auto Container<T>::begin() noexcept
	{
		return std::ranges::begin(range_);
	}

	template <std::ranges::common_range T>
	constexpr auto Container<T>::end() const noexcept
	{
		return std::ranges::cend(range_);
	}

	template <std::ranges::common_range T>
	constexpr auto Container<T>::end() noexcept
	{
		return std::ranges::end(range_);
	}
}

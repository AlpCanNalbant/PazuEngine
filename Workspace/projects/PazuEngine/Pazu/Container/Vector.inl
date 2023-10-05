// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

// namespace Pazu
// {
// 	template <typename T, typename TKey>
// 	template <typename... Types>
// 	constexpr void Vector<T, TKey>::Add(Types &&...args)
// 	{
// 		constexpr auto &myValues = Container<T>::values_;
// 		Container<T>::values_.emplace_back(std::forward<Types>(args)...);
// 	}

// 	template <typename T, typename TKey>
// 	constexpr void Vector<T, TKey>::AddRange(const Vector &vector)
// 	{
// 		const auto &otherValues = vector.values_;
// 		SetCount(Container<T>::values_.size() + otherValues.size());

// 		for (auto [first, firstOther] = {values_.end() - otherValues.size(), otherValues.cbegin()};
// 				 first != values_.cend(); ++first)
// 		{
// 		}
// 	}

// 	template <typename T, typename TKey>
// 	constexpr void Vector<T, TKey>::AddRange(Vector &&vector)
// 	{
// 	}

// 	template <typename T, typename TKey>
// 	constexpr const T &Find(const TKey &key) requires(!std::is_void_v<TKey>)
// 	{
// 	}

// 	template <typename T, typename TKey>
// 	constexpr void Vector<T, TKey>::SetCapacity(const std::size_t capacity) noexcept
// 	{
// 		Container<T>::values_.reserve(capacity);
// 	}

// 	template <typename T, typename TKey>
// 	constexpr T &Vector<T, TKey>::operator[](const std::size_t index) const noexcept
// 	{
// 	}
// }

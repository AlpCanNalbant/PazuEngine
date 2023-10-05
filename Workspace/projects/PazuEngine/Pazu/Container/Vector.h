// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

// #pragma once
// #include "Container.h"

// namespace Pazu
// {
// 	template <typename T, typename TKey = void>
// 	class Vector : public virtual Container<std::vector<T>>
// 	{
// 	public:
// 		using Container<std::vector<T>>::Container;

// 		constexpr void AddRange(const Vector &vector);
// 		constexpr void AddRange(Vector &&vector);
// 		constexpr const T &Find(const TKey &key) requires(!std::is_void_v<TKey>);

// 		constexpr void SetCapacity(const std::size_t capacity) noexcept;

// 		Vector &operator=(const Vector &other) = default;
// 		Vector &operator=(Vector &&other) = default;
// 		constexpr T &operator[](const std::size_t index) const noexcept;
// 	};
// }

// #include "Vector.inl"

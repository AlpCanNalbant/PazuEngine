#pragma once

namespace Pazu
{
	template <typename T>
	using SharedPtr = std::shared_ptr<T>;
	template <typename T, typename TDelete = std::default_delete<T>>
	using Unique = std::unique_ptr<T, TDelete>;
	template <typename T>
	using Ref = std::reference_wrapper<T>;
	using UniqueHandle = std::unique_ptr<void>;
	using Handle = std::shared_ptr<void>;
	using String = std::string;
	template <typename TKey, typename TValue, typename THash = std::hash<TKey>, typename TPred = std::equal_to<TKey>, typename TAlloc = std::pair<const TKey, TValue>>
	using UnorderedMap = std::unordered_map<TKey, TValue, THash, TPred, TAlloc>;
	using TypeIndex = std::type_index;
	template <typename T>
	using WeakPtr = std::weak_ptr<T>;
	using TNullPtr = std::nullptr_t;
	template <typename T, std::size_t Lenght>
	using Array = std::array<T, Lenght>;
	template <typename T>
	using Vector = std::vector<T>;

	template <typename T, typename... Args>
	SharedPtr<T> MakeShared(Args &&...args) noexcept;
	template <typename T>
	SharedPtr<T> StaticPtrCast(const SharedPtr<T> &ptr) noexcept;
	template <typename T>
	SharedPtr<T> DynamicPtrCast(const SharedPtr<T> &ptr) noexcept;
	template <typename T>
	SharedPtr<T> ReinterpretPtrCast(const SharedPtr<T> &ptr) noexcept;
	template <typename T, typename... Args>
	Unique<T> CreateUnique(Args &&...args) noexcept;
	template <typename T>
	Ref<T> ToRef(T &value) noexcept;
	template <typename T>
	String ToString(const T number) noexcept;
}
#include "Globals.inl"

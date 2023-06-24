namespace Pazu
{
	template <typename T, typename... Args>
	SharedPtr<T> MakeShared(Args &&...args) noexcept
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	SharedPtr<T> StaticPtrCast(const SharedPtr<T> &ptr) noexcept
	{
		return std::static_pointer_cast<T>(ptr);
	}

	template <typename T>
	SharedPtr<T> DynamicPtrCast(const SharedPtr<T> &ptr) noexcept
	{
		return std::dynamic_pointer_cast<T>(ptr);
	}

	template <typename T>
	SharedPtr<T> ReinterpretPtrCast(const SharedPtr<T> &ptr) noexcept
	{
		return std::reinterpret_pointer_cast<T>(ptr);
	}

	template <typename T, typename... Args>
	Unique<T> CreateUnique(Args &&...args) noexcept
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	Ref<T> ToRef(T &value) noexcept
	{
		if constexpr (std::is_const_v<T>)
			return std::cref(value);
		else
			return std::ref(value);
	}

	template <typename T>
	String ToString(const T number) noexcept
	{
		return std::to_string(number);
	}
}

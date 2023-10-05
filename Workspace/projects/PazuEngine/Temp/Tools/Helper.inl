// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename From, typename To>
	inline constexpr bool Helper::GetStaticCastable()
	{
		return StaticCastable<From, To>::value;
	}
}

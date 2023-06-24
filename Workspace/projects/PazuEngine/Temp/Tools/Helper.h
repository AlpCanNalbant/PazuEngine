#pragma once

namespace Pazu
{
	class Helper : public INonCreatable
	{
	public:
		template <typename From, typename To>
		static constexpr bool GetStaticCastable();

	private:
		template <typename From, typename To, typename = To>
		struct StaticCastable : std::false_type
		{
		};

		template <typename From, typename To>
		struct StaticCastable<From, To, decltype(static_cast<To>(std::declval<From>()))> : std::true_type
		{
		};
	};
}
#include "Helper.inl"

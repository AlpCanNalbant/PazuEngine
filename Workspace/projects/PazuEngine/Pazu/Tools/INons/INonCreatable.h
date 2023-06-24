#pragma once

namespace Pazu
{
	class INonCreatable
	{
	public:
		INonCreatable() = delete;
		INonCreatable(const INonCreatable &other) = delete;
		INonCreatable(INonCreatable &&other) = delete;
		virtual ~INonCreatable() = 0;
		INonCreatable &operator=(const INonCreatable &other) = delete;
		INonCreatable &operator=(INonCreatable &&other) = delete;
	};
}

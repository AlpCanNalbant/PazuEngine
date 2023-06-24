#pragma once

namespace Pazu
{
	class INonMovable
	{
	public:
		INonMovable() = default;
		INonMovable(const INonMovable &other) = default;
		INonMovable(INonMovable &&other) = delete;
		virtual ~INonMovable() = 0;
		INonMovable &operator=(const INonMovable &other) = default;
		INonMovable &operator=(INonMovable &&other) = delete;
	};
}

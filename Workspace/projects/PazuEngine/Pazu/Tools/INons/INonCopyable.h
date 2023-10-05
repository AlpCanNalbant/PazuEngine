// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	class INonCopyable
	{
	public:
		INonCopyable() = default;
		INonCopyable(const INonCopyable &other) = delete;
		INonCopyable(INonCopyable &&other) = default;
		virtual ~INonCopyable() = 0;
		INonCopyable &operator=(const INonCopyable &other) = delete;
		INonCopyable &operator=(INonCopyable &&other) = default;
	};
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	struct InfoVersion
	{
		InfoVersion() = default;
		InfoVersion(const int major, const int minor, const int patch = -1);
		std::string ToString() const;

		int major{0};
		int minor{0};
		int patch{-1};
	};
} // namespace Pazu

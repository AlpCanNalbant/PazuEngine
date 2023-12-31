// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	struct VideoMode
	{
		VideoMode() = default;
		VideoMode(const Size &size, const std::vector<unsigned int> &refreshRates);

		Size size;
		std::vector<unsigned int> refreshRates;
	};
}

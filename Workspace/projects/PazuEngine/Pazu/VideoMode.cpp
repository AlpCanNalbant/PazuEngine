// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "VideoMode.h"

namespace Pazu
{
	VideoMode::VideoMode(const Size &size, const std::vector<unsigned int> &refreshRates)
		: size(size), refreshRates(refreshRates) {}
}

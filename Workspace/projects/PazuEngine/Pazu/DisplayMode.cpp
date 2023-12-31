// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "DisplayMode.h"

namespace Pazu
{
	DisplayMode::DisplayMode(const unsigned int index, const std::string &name, const std::vector<VideoMode> &videoModes)
		: index(index), name(name), videoModes(videoModes) {}
}

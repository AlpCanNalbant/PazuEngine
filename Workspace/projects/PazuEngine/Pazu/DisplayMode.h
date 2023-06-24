#pragma once
#include "VideoMode.h"

namespace Pazu
{
	struct DisplayMode
	{
		DisplayMode() = default;
		DisplayMode(const unsigned int index, const std::string &name, const std::vector<VideoMode> &videoModes);

		unsigned int index;
		std::string name;
		std::vector<VideoMode> videoModes;
	};
}

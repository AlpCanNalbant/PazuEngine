// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "DisplayMode.h"

namespace Pazu
{
	class Window;
	class Display : public INonCopyable
	{
	public:
		static Display &Get();
		const std::vector<DisplayMode> &GetModes() const;
		const DisplayMode &GetWindowMode(const Window &window) const;

	private:
		Display();
		std::vector<VideoMode> FindVideoModes(const unsigned int index) const;

		std::vector<DisplayMode> m_displayModes;
	};
}

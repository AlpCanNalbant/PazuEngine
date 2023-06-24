#pragma once
#include "RenderScaleQuality.h"
#include "RenderDriver.h"

namespace Pazu::Sdl
{
	struct DeviceConfig
	{
		DeviceConfig() = default;
		DeviceConfig(const bool closeOnAltF4, const RenderScaleQuality renderScaleQuality, const RenderDriver renderDriver, const bool override);
		void ResetSettings() const;
		bool GetCloseOnAltF4() const;
		RenderScaleQuality GetRenderScaleQuality() const;
		RenderDriver GetRenderDriver() const;
		void SetCloseOnAltF4(const bool closeOnAltF4, const bool override) const;
		void SetRenderScaleQuality(const RenderScaleQuality renderScaleQuality, const bool override) const;
		void SetRenderDriver(const RenderDriver renderDriver, const bool override) const;
	};
} // namespace Pazu

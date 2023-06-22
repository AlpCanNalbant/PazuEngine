#include <algorithm>
#include "DeviceConfig.h"
using namespace magic_enum;

namespace Pazu::Sdl
{
	DeviceConfig::DeviceConfig(const bool closeOnAltF4, const RenderScaleQuality renderScaleQuality, const RenderDriver renderDriver, const bool override)
	{
		SetRenderDriver(renderDriver, override);
		SetRenderScaleQuality(renderScaleQuality, override);
		SetCloseOnAltF4(closeOnAltF4, override);
	}

	void DeviceConfig::ResetSettings() const
	{
		SDL_ClearHints();
	}

	bool DeviceConfig::GetCloseOnAltF4() const
	{
		if (const auto &hintValue = SDL_GetHint(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4))
			return std::string(hintValue) == "0";
		return Log::Get().Print<LogMode::Error, bool>("CloseOnAltF4 bulunamadi.");
	}

	RenderScaleQuality DeviceConfig::GetRenderScaleQuality() const
	{
		if (const auto &hintValue = SDL_GetHint(SDL_HINT_RENDER_SCALE_QUALITY))
			return enum_cast<RenderScaleQuality>(hintValue).value_or(RenderScaleQuality::None);
		return Log::Get().Print<LogMode::Error, RenderScaleQuality>("RenderScaleQuality bulunamadi.");
	}

	RenderDriver DeviceConfig::GetRenderDriver() const
	{
		if (const auto &hintValue = SDL_GetHint(SDL_HINT_RENDER_DRIVER))
			return enum_cast<RenderDriver>(hintValue).value_or(RenderDriver::None);
		return Log::Get().Print<LogMode::Error, RenderDriver>("RenderDriver bulunamadi.");
	}

	void DeviceConfig::SetCloseOnAltF4(const bool closeOnAltF4, const bool override) const
	{
		if (const auto &hintValue = closeOnAltF4 ? "0" : "1"; SDL_SetHintWithPriority(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4, hintValue, override ? SDL_HINT_OVERRIDE : SDL_HINT_NORMAL) == SDL_FALSE)
			Log::Get().Print<LogMode::Error>("CloseOnAltF4=" + std::to_string(closeOnAltF4) + " ayarlanamadi.");
	}

	void DeviceConfig::SetRenderScaleQuality(const RenderScaleQuality renderScaleQuality, const bool override) const
	{
		if (const auto &hintValue = std::to_string(enum_integer<RenderScaleQuality>(renderScaleQuality)); SDL_SetHintWithPriority(SDL_HINT_RENDER_SCALE_QUALITY, hintValue.c_str(), override ? SDL_HINT_OVERRIDE : SDL_HINT_NORMAL) == SDL_FALSE)
			Log::Get().Print<LogMode::Error>("RenderScaleQuality=" + std::string(enum_name(renderScaleQuality)) + " ayarlanamadi.");
	}

	void DeviceConfig::SetRenderDriver(const RenderDriver renderDriver, const bool override) const
	{
		std::string hintValue(enum_name(renderDriver));
		std::transform(hintValue.begin(), hintValue.end(), hintValue.begin(), [](auto c)
									 { return std::tolower(c); });
		if (SDL_SetHintWithPriority(SDL_HINT_RENDER_DRIVER, hintValue.c_str(), override ? SDL_HINT_OVERRIDE : SDL_HINT_NORMAL) == SDL_FALSE)
			Log::Get().Print<LogMode::Error>("RenderDriver=" + std::string(enum_name(renderDriver)) + " ayarlanamadi.");
#if defined(_DEBUG)
		if (renderDriver == RenderDriver::Direct3D11)
		{
			if (SDL_SetHintWithPriority(SDL_HINT_RENDER_DIRECT3D11_DEBUG, "1", override ? SDL_HINT_OVERRIDE : SDL_HINT_NORMAL) == SDL_FALSE)
				Log::Get().Print<LogMode::Error>("RenderDirect3D11Debug=1 ayarlanamadi.");
		}
#endif
	}
} // namespace Pazu

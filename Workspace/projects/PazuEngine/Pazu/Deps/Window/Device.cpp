#include "Device.h"
using namespace magic_enum::flags;

namespace Pazu::Sdl
{
	Device::Device(const InitFlag flags, const DeviceConfig &config)
			: config(config)
	{
#ifdef SDL_MAIN_HANDLED
		Log::Get().Print<LogMode::Info>("SDL_MAIN_HANDLED aktiflestirildi.");
		SDL_SetMainReady();
#endif
		if (SDL_Init(enum_integer(flags)) != 0)
			Log::Get().Print<LogMode::Fatal>(GetInfo().ToString() + " kurulamadi. SDL hata mesaji: " + SDL_GetError());
		// std::atexit(SDL_Quit);
		// if (SDL_GL_LoadLibrary(nullptr) != 0) //Pencere olusturulmadan önce kullanılmalı
		// Log::Get().Print<LogMode::Error>({"SDL varsayilan OpenGL yuklenemedi. SDL hata mesaji: ", SDL_GetError()});
		Log::Get().Print<LogMode::Info>(GetInfo().ToString() + " kuruldu.");
	}

	Device::~Device()
	{
		SDL_Quit();
	}

	InfoTitleVersion Device::GetInfo() const
	{
		SDL_version sdlVersion;
		SDL_GetVersion(&sdlVersion);
		return {"SDL", {sdlVersion.major, sdlVersion.minor, sdlVersion.patch}};
	}
} // namespace Pazu

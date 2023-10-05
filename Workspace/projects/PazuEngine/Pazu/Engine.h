// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "Graphics/Api.h"
#include "Deps/Window/Device.h"

namespace Pazu
{
	namespace Graphics
	{
		class Context;
	}
	namespace Sdl
	{
		class Device;
	}
	class Window;
	class Engine : public INonCreatable
	{
	public:
		static void Init(const Graphics::Api graphicsApi);
		static Graphics::Api GetGraphicsApi();

	private:
		static std::unique_ptr<Sdl::Device> m_sdlDevice;
		static Graphics::Api m_graphicsApi;
	};
}

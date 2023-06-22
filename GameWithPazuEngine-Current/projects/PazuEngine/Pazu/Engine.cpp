#include "Engine.h"

namespace Pazu
{
	using namespace Graphics;
	std::unique_ptr<Sdl::Device> Engine::m_sdlDevice;
	Api Engine::m_graphicsApi;

	void Engine::Init(const Api graphicsApi)
	{
		using namespace Sdl;
		m_graphicsApi = graphicsApi;
		switch (graphicsApi)
		{
		case Api::Direct3D11:
			m_sdlDevice = std::make_unique<Device>(InitFlag::Video, DeviceConfig(true, RenderScaleQuality::Anisotropic, RenderDriver::Direct3D11, false));
			break;
		case Api::OpenGL:
			m_sdlDevice = std::make_unique<Device>(InitFlag::Video, DeviceConfig(true, RenderScaleQuality::Linear, RenderDriver::OpenGL, false));
			break;
		default:
			break;
		}
	}

	Api Engine::GetGraphicsApi()
	{
		return m_graphicsApi;
	}
}

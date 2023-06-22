#include <Pazu/Event/WindowEventData.h>
#include <Pazu/Window.h>
#include <Pazu/Graphics/Context.h>
#include <Pazu/System/SystemManager.h>
#include "MyWindowEvent.h"
using namespace Pazu;
using namespace Pazu::Graphics;

MyWindowEvent::MyWindowEvent(const std::shared_ptr<Context> &graphicsContext, const std::shared_ptr<SystemManager> &systemManager) noexcept
		: m_graphicsContext(graphicsContext), m_systemManager(systemManager) {}

void MyWindowEvent::OnEvent(const WindowEventData &data) noexcept
{
	switch (data.GetState())
	{
	case WindowEventState::Resized:
		if (m_graphicsContext)
			m_graphicsContext->Resize(data.GetSize());
		if (m_systemManager)
			m_systemManager->Resize(data.GetSize());
		break;
	default:
		break;
	}
}

void MyWindowEvent::SetGraphicsContext(const std::shared_ptr<Context> &graphicsContext) noexcept
{
	m_graphicsContext = graphicsContext;
}

void MyWindowEvent::SetSystemManager(const std::shared_ptr<SystemManager> &systemManager) noexcept
{
	m_systemManager = systemManager;
}

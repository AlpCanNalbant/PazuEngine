#pragma once
#include <Pazu/Event/WindowEvent.h>

namespace Pazu
{
	class Window;
	class SystemManager;
	namespace Graphics
	{
		class Context;
	}
}
class MyWindowEvent : public Pazu::WindowEvent
{
public:
	MyWindowEvent() noexcept = default;
	MyWindowEvent(const std::shared_ptr<Pazu::Graphics::Context> &graphicsContext, const std::shared_ptr<Pazu::SystemManager> &systemManager) noexcept;
	void OnEvent(const Pazu::WindowEventData &data) noexcept final;
	void SetGraphicsContext(const std::shared_ptr<Pazu::Graphics::Context> &graphicsContext) noexcept;
	void SetSystemManager(const std::shared_ptr<Pazu::SystemManager> &systemManager) noexcept;

private:
	std::shared_ptr<Pazu::Graphics::Context> m_graphicsContext;
	std::shared_ptr<Pazu::SystemManager> m_systemManager;
};

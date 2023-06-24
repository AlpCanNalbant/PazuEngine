#include "EventManager.h"
using namespace magic_enum;

namespace Pazu
{
	EventManager::EventManager()
	{
		m_events.fill(std::make_shared<NoneEvent>());
	}

	void EventManager::Update()
	{
		for (const auto &updatableEvent : m_updatableEvents)
			updatableEvent->OnUpdate();
		while (SDL_PollEvent(&m_sdlEvent))
		{
			const auto &[type, data] = GetInfo(m_sdlEvent.type);
			m_events[enum_integer(type)]->OnEvent(data);
		}
	}

	std::pair<EventType, std::reference_wrapper<const IEventData>> EventManager::GetInfo(const unsigned int sdlEventType) const
	{
		static const MouseEventData mouseData(m_sdlEvent.type, m_sdlEvent.motion.x, m_sdlEvent.motion.y, m_sdlEvent.motion.xrel, m_sdlEvent.motion.yrel, m_sdlEvent.wheel.y, m_sdlEvent.button.button);
		static const KeyboardEventData keyboardData(m_sdlEvent.type, m_sdlEvent.key.keysym.scancode);
		static const WindowEventData windowData(m_sdlEvent.window.windowID, m_sdlEvent.window.event, m_sdlEvent.window.data1, m_sdlEvent.window.data2);
		static const SystemEventData systemData(m_sdlEvent.type);
		static const NoneEventData noneData;

		if ((sdlEventType == SDL_MOUSEBUTTONDOWN) || (sdlEventType == SDL_MOUSEBUTTONUP) || (sdlEventType == SDL_MOUSEMOTION) || (sdlEventType == SDL_MOUSEWHEEL))
			return std::make_pair(EventType::Mouse, std::cref(mouseData));
		else if ((sdlEventType == SDL_KEYDOWN) || (sdlEventType == SDL_KEYUP))
			return std::make_pair(EventType::Keyboard, std::cref(keyboardData));
		else if (sdlEventType == SDL_WINDOWEVENT)
			return std::make_pair(EventType::Window, std::cref(windowData));
		else if (sdlEventType == SDL_QUIT)
			return std::make_pair(EventType::System, std::cref(systemData));
		return std::make_pair(EventType::None, std::cref(noneData));
	}
} // namespace Pazu

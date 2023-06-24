#pragma once
#include "EventType.h"
#include "IUpdatableEvent.h"
#include "NoneEvent.h"
#include "NoneEventData.h"
#include "WindowEventData.h"
#include "MouseEventData.h"
#include "KeyboardEventData.h"
#include "SystemEventData.h"

namespace Pazu
{
	class EventManager
	{
	public:
		EventManager();
		template <typename T>
		void Add(const std::shared_ptr<T> &event);
		template <typename T>
		void Remove(const std::shared_ptr<T> &event);
		void Update();

	private:
		std::pair<EventType, std::reference_wrapper<const IEventData>> GetInfo(const unsigned int sdlEventType) const;
		std::array<std::shared_ptr<IEvent>, magic_enum::enum_count<EventType>()> m_events;
		std::vector<std::shared_ptr<IUpdatableEvent>> m_updatableEvents;
		SDL_Event m_sdlEvent;
	};
} // namespace Pazu
#include "EventManager.inl"

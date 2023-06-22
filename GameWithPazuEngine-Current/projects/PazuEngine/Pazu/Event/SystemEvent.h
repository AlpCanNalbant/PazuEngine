#pragma once
#include "IEvent.h"

namespace Pazu
{
	class SystemEvent : public IEvent
	{
	public:
		void OnEvent(const IEventData &data) final;
		EventType GetType() const final;
		bool ShouldQuit() const;

	private:
		bool m_shouldQuit{false};
	};
} // namespace Pazu

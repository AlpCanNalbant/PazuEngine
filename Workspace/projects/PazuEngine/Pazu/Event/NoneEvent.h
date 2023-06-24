#pragma once
#include "IEvent.h"

namespace Pazu
{
	class NoneEvent : public IEvent
	{
	public:
		void OnEvent(const IEventData &data) final;
		EventType GetType() const final;
	};
} // namespace Pazu

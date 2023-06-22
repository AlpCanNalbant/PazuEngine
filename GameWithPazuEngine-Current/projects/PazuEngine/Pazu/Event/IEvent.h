#pragma once
#include "EventType.h"

namespace Pazu
{
	struct IEventData;
	class IEvent
	{
	public:
		virtual ~IEvent() = default;
		virtual void OnEvent(const IEventData &data) = 0;
		virtual EventType GetType() const = 0;
	};
} // namespace Pazu

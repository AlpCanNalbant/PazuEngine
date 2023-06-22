#include "NoneEvent.h"

namespace Pazu
{
	void NoneEvent::OnEvent(const IEventData &data [[gnu::unused]]) {}

	EventType NoneEvent::GetType() const
	{
		return EventType::None;
	}
} // namespace Pazu

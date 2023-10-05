// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "WindowEventData.h"
#include "WindowEvent.h"

namespace Pazu
{
	void WindowEvent::OnEvent(const IEventData &data)
	{
		OnEvent(static_cast<const WindowEventData &>(data));
	}

	EventType WindowEvent::GetType() const
	{
		return EventType::Window;
	}
} // namespace Pazu

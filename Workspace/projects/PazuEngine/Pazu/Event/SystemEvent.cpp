// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "SystemEventData.h"
#include "SystemEvent.h"

namespace Pazu
{
	void SystemEvent::OnEvent(const IEventData &data)
	{
		const auto &systemData = static_cast<const SystemEventData &>(data);
		if (systemData.GetState() == SystemEventState::Quit)
			m_shouldQuit = true;
	}

	EventType SystemEvent::GetType() const
	{
		return EventType::System;
	}

	bool SystemEvent::ShouldQuit() const
	{
		return m_shouldQuit;
	}
} // namespace Pazu

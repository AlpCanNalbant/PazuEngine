#include "MouseEventData.h"
#include "MouseEvent.h"
using namespace magic_enum;

namespace Pazu
{
	void MouseEvent::OnUpdate()
	{
		m_mouseState[m_lastButtonCode][1] = false;
		m_mouseState[m_lastButtonCode][2] = false;
	}

	void MouseEvent::OnEvent(const MouseEventData &data [[gnu::unused]]) {}

	void MouseEvent::OnEvent(const IEventData &data)
	{
		const auto &mouseData = static_cast<const MouseEventData &>(data);
		if (const auto stateId = mouseData.stateId; stateId == SDL_MOUSEBUTTONDOWN)
		{
			m_lastButtonCode = mouseData.buttonCode;
			m_mouseState[m_lastButtonCode][1] = !m_mouseState[m_lastButtonCode][0];
			m_mouseState[m_lastButtonCode][0] = true;
		}
		else if (stateId == SDL_MOUSEBUTTONUP)
		{
			m_lastButtonCode = mouseData.buttonCode;
			m_mouseState[m_lastButtonCode][2] = true;
			m_mouseState[m_lastButtonCode][0] = false;
		}
		OnEvent(mouseData);
	}

	EventType MouseEvent::GetType() const
	{
		return EventType::Mouse;
	}

	bool MouseEvent::GetButtonDown(const Button button) const
	{
		return m_mouseState[enum_integer(button)][0];
	}

	bool MouseEvent::GetButtonHit(const Button button) const
	{
		return m_mouseState[enum_integer(button)][1];
	}

	bool MouseEvent::GetButtonUp(const Button button) const
	{
		return m_mouseState[enum_integer(button)][2];
	}

	bool MouseEvent::GetRelativeMode() const
	{
		return SDL_GetRelativeMouseMode();
	}

	void MouseEvent::SetRelativeMode(const bool enabled) const
	{
		SDL_SetRelativeMouseMode(static_cast<SDL_bool>(enabled));
	}
} // namespace Pazu

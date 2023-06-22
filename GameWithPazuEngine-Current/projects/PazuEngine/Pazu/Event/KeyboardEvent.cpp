#include "KeyboardEventData.h"
#include "KeyboardEvent.h"
using namespace magic_enum;

namespace Pazu
{
	void KeyboardEvent::OnUpdate()
	{
		m_keyboardState[m_lastKeyCode][1] = false;
		m_keyboardState[m_lastKeyCode][2] = false;
	}

	void KeyboardEvent::OnEvent(const KeyboardEventData &data [[gnu::unused]]) {}

	void KeyboardEvent::OnEvent(const IEventData &data)
	{
		const auto &keyboardData = static_cast<const KeyboardEventData &>(data);
		m_lastKeyCode = keyboardData.keyCode;
		if (const auto stateId = keyboardData.stateId; stateId == SDL_KEYDOWN)
		{
			m_keyboardState[m_lastKeyCode][1] = !m_keyboardState[m_lastKeyCode][0];
			m_keyboardState[m_lastKeyCode][0] = true;
		}
		else if (stateId == SDL_KEYUP)
		{
			m_keyboardState[m_lastKeyCode][2] = true;
			m_keyboardState[m_lastKeyCode][0] = false;
		}
		OnEvent(keyboardData);
	}

	EventType KeyboardEvent::GetType() const
	{
		return EventType::Keyboard;
	}

	bool KeyboardEvent::GetKeyDown(const Key key) const
	{
		return m_keyboardState[enum_integer(key)][0];
	}

	bool KeyboardEvent::GetKeyHit(const Key key) const
	{
		return m_keyboardState[enum_integer(key)][1];
	}

	bool KeyboardEvent::GetKeyUp(const Key key) const
	{
		return m_keyboardState[enum_integer(key)][2];
	}
} // namespace Pazu

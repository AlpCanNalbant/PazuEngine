// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <bitset>
#include "Key.h"
#include "IUpdatableEvent.h"

namespace Pazu
{
	struct KeyboardEventData;
	class KeyboardEvent : public IUpdatableEvent
	{
	public:
		KeyboardEvent() = default;
		KeyboardEvent(const KeyboardEvent &other) = default;
		KeyboardEvent(KeyboardEvent &&other) = default;
		virtual ~KeyboardEvent() = default;
		KeyboardEvent &operator=(const KeyboardEvent &other) = default;
		KeyboardEvent &operator=(KeyboardEvent &&other) = default;
		void OnUpdate() final;
		virtual void OnEvent(const KeyboardEventData &data);
		EventType GetType() const final;
		bool GetKeyDown(const Key key) const;
		bool GetKeyHit(const Key key) const;
		bool GetKeyUp(const Key key) const;

	private:
		void OnEvent(const IEventData &data) final;

		std::size_t m_lastKeyCode{0};
		std::array<std::bitset<3>, magic_enum::enum_count<Key>()> m_keyboardState;
	};
} // namespace Pazu

#pragma once
#include <bitset>
#include "Button.h"
#include "IUpdatableEvent.h"

namespace Pazu
{
	struct MouseEventData;
	class MouseEvent : public IUpdatableEvent
	{
	public:
		MouseEvent() = default;
		MouseEvent(const MouseEvent &other) = default;
		MouseEvent(MouseEvent &&other) = default;
		virtual ~MouseEvent() = default;
		MouseEvent &operator=(const MouseEvent &other) = default;
		MouseEvent &operator=(MouseEvent &&other) = default;
		void OnUpdate() final;
		virtual void OnEvent(const MouseEventData &data);
		EventType GetType() const final;
		bool GetButtonDown(const Button button) const;
		bool GetButtonHit(const Button button) const;
		bool GetButtonUp(const Button button) const;
		bool GetRelativeMode() const;
		void SetRelativeMode(const bool enabled) const;

	private:
		void OnEvent(const IEventData &data) final;

		std::size_t m_lastButtonCode{0};
		std::array<std::bitset<3>, magic_enum::enum_count<Button>()> m_mouseState;
	};
} // namespace Pazu

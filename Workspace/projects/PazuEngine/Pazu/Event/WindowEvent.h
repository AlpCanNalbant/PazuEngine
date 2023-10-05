// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <functional>
#include "WindowEventState.h"
#include "IEvent.h"

namespace Pazu
{
	struct WindowEventData;
	class WindowEvent : public IEvent
	{
	public:
		WindowEvent() = default;
		WindowEvent(const WindowEvent &other) = default;
		WindowEvent(WindowEvent &&other) = default;
		virtual ~WindowEvent() = default;
		WindowEvent &operator=(const WindowEvent &other) = default;
		WindowEvent &operator=(WindowEvent &&other) = default;
		virtual void OnEvent(const WindowEventData &data) = 0;
		EventType GetType() const final;

	private:
		void OnEvent(const IEventData &data) final;
	};
} // namespace Pazu

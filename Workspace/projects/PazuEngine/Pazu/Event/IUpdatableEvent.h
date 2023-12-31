// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "IEvent.h"

namespace Pazu
{
	class IUpdatableEvent : public IEvent
	{
	public:
		virtual ~IUpdatableEvent() = default;
		virtual void OnUpdate() = 0;
	};
} // namespace Pazu

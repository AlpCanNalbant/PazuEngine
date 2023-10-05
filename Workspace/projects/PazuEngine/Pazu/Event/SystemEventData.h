// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "SystemEventState.h"
#include "IEventData.h"

namespace Pazu
{
	struct SystemEventData : public IEventData
	{
		SystemEventData(const unsigned int &stateId);
		SystemEventState GetState() const;

		const unsigned int &stateId;
	};
} // namespace Pazu

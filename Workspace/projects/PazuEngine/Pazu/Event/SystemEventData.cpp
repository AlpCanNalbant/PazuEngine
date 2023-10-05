// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "SystemEventData.h"
using namespace magic_enum;

namespace Pazu
{
	SystemEventData::SystemEventData(const unsigned int &stateId)
		: stateId(stateId) {}

	SystemEventState SystemEventData::GetState() const
	{
		return enum_cast<SystemEventState>(stateId).value_or(SystemEventState::None);
	}
} // namespace Pazu

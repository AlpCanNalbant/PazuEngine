// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "WindowEventData.h"
using namespace magic_enum;

namespace Pazu
{
	WindowEventData::WindowEventData(const unsigned int &handleId, const unsigned char &stateId, const int &data1, const int &data2)
		: handleId(handleId), stateId(stateId), x(data1), y(data2) {}

	WindowEventState WindowEventData::GetState() const
	{
		return enum_cast<WindowEventState>(stateId).value_or(WindowEventState::None);
	}

	Point WindowEventData::GetPosition() const
	{
		return {x, y};
	}

	Size WindowEventData::GetSize() const
	{
		return {static_cast<unsigned int>(x), static_cast<unsigned int>(y)};
	}
} // namespace Pazu

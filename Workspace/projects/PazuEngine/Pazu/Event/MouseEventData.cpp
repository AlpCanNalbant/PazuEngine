// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "MouseEventData.h"
using namespace magic_enum;

namespace Pazu
{
	MouseEventData::MouseEventData(const unsigned int &stateId, const int &x, const int &y, const int &relativeX, const int &relativeY, const int &wheel, const unsigned char &buttonCode)
		: stateId(stateId), x(x), y(y), relativeX(relativeX), relativeY(relativeY), wheel(wheel), buttonCode(buttonCode) {}

	MouseEventState MouseEventData::GetState() const
	{
		return enum_cast<MouseEventState>(stateId).value_or(MouseEventState::None);
	}

	Point MouseEventData::GetPosition() const
	{
		return {x, y};
	}

	Point MouseEventData::GetRelativePosition() const
	{
		return {relativeX, relativeY};
	}

	Button MouseEventData::GetButton() const
	{
		return enum_cast<Button>(buttonCode).value_or(Button::None);
	}
} // namespace Pazu

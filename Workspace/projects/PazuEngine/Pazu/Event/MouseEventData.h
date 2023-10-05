// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "MouseEventState.h"
#include "Button.h"
#include "IEventData.h"

namespace Pazu
{
	struct MouseEventData : public IEventData
	{
		MouseEventData(const unsigned int &stateId, const int &x, const int &y, const int &relativeX, const int &relativeY, const int &wheel, const unsigned char &buttonCode);
		MouseEventState GetState() const;
		Point GetPosition() const;
		Point GetRelativePosition() const;
		Button GetButton() const;

		const unsigned int &stateId;
		const int &x, &y;
		const int &relativeX, &relativeY;
		const int &wheel;
		const unsigned char &buttonCode;
	};
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "KeyboardEventState.h"
#include "Key.h"
#include "KeyCode.h"
#include "IEventData.h"

namespace Pazu
{
	struct KeyboardEventData : public IEventData
	{
		KeyboardEventData(const unsigned int &stateId, const SDL_Scancode &keyCode);
		KeyboardEventState GetState() const;
		Key GetKey() const;

		const unsigned int &stateId;
		const KeyCode &keyCode;
	};
} // namespace Pazu

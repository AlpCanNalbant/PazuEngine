// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "KeyboardEventData.h"
using namespace magic_enum;

namespace Pazu
{
	KeyboardEventData::KeyboardEventData(const unsigned int &stateId, const SDL_Scancode &keyCode)
		: stateId(stateId), keyCode(keyCode) {}

	KeyboardEventState KeyboardEventData::GetState() const
	{
		return enum_cast<KeyboardEventState>(stateId).value_or(KeyboardEventState::None);
	}

	Key KeyboardEventData::GetKey() const
	{
		return enum_cast<Key>(keyCode).value_or(Key::None);
	}
} // namespace Pazu

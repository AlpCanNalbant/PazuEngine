#pragma once
#include "WindowEventState.h"
#include "IEventData.h"

namespace Pazu
{
	struct WindowEventData : public IEventData
	{
		WindowEventData(const unsigned int &handleId, const unsigned char &stateId, const int &data1, const int &data2);
		WindowEventState GetState() const;
		Point GetPosition() const;
		Size GetSize() const;

		const unsigned int &handleId;
		const unsigned char &stateId;
		const int &x, &y;
	};
} // namespace Pazu

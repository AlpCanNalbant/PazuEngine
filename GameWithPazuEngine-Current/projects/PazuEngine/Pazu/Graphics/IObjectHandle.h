#pragma once

namespace Pazu::Graphics
{
	class IObjectHandle : public INonCopyable
	{
	public:
		virtual ~IObjectHandle() = 0;
	};
}

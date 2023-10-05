// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	class IObjectHandle : public INonCopyable
	{
	public:
		virtual ~IObjectHandle() = 0;
	};
}

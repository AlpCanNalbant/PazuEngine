// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "ContextConfig.h"

namespace Pazu::Graphics
{
	unsigned int ContextConfig::GetBufferCount() const
	{
		return !tripleBuffering ? 2 : 3;
	}
}

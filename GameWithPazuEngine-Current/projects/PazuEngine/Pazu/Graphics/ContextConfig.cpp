#include "ContextConfig.h"

namespace Pazu::Graphics
{
	unsigned int ContextConfig::GetBufferCount() const
	{
		return !tripleBuffering ? 2 : 3;
	}
}

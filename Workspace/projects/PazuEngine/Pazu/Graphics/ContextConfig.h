#pragma once

namespace Pazu::Graphics
{
	struct ContextConfig
	{
		ContextConfig() = default;
		constexpr ContextConfig(const unsigned int antialiasingLevel, const bool tripleBuffering);
		unsigned int GetBufferCount() const;

		unsigned int antialiasingLevel{4};
		bool tripleBuffering{false};
	};
}
#include "ContextConfig.inl"

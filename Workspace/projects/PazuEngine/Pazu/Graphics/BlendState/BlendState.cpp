// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "BlendState.h"

namespace Pazu::Graphics
{
	BlendState::BlendState(const bool enable, const Color &factor)
		: m_enable(enable), m_factor(factor) {}

	bool BlendState::GetEnable() const
	{
		return m_enable;
	}

	const Color &BlendState::GetFactor() const
	{
		return m_factor;
	}

	Color &BlendState::GetFactor()
	{
		return m_factor;
	}

	void BlendState::SetEnable(const bool enable)
	{
		m_enable = enable;
	}

	void BlendState::SetFactor(const Color &factor)
	{
		m_factor = factor;
	}
}

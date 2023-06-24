#pragma once
#include "../../Math/Color.h"
#include "../Object.h"

namespace Pazu::Graphics
{
	class BlendState : public Object
	{
	public:
		BlendState() = default;
		BlendState(const bool enable, const Color &factor);
		bool GetEnable() const;
		const Color &GetFactor() const;
		Color &GetFactor();
		void SetEnable(const bool enable);
		void SetFactor(const Color &factor);

	private:
		bool m_enable;
		Color m_factor;
	};
} // namespace Pazu

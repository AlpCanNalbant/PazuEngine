#pragma once

namespace Pazu
{
	class IResizableSystem
	{
	public:
		virtual void Resize(const Size &size) = 0;
	};
}

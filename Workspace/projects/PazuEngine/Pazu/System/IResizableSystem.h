// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	class IResizableSystem
	{
	public:
		virtual void Resize(const Size &size) = 0;
	};
}

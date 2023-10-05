// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "InfoVersion.h"

namespace Pazu
{
	struct InfoTitleVersion
	{
		InfoTitleVersion() = default;
		InfoTitleVersion(const std::string &title, const InfoVersion &version);
		std::string ToString() const;

		std::string title;
		InfoVersion version;
	};
} // namespace Pazu

#include "InfoVersion.h"

namespace Pazu
{
	InfoVersion::InfoVersion(const int major, const int minor, const int patch)
			: major(major), minor(minor), patch(patch) {}

	std::string InfoVersion::ToString() const
	{
		if (patch != -1)
			return {std::to_string(major) + "." + std::to_string(minor) + '.' + std::to_string(patch)};
		else
			return {std::to_string(major) + "." + std::to_string(minor)};
	}
} // namespace Pazu

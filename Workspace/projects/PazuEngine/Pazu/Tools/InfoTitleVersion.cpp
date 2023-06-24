#include "InfoTitleVersion.h"

namespace Pazu
{
	InfoTitleVersion::InfoTitleVersion(const std::string &title, const InfoVersion &version)
			: title(title), version(version) {}

	std::string InfoTitleVersion::ToString() const
	{
		return title + ' ' + version.ToString();
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "File.h"

namespace Pazu
{
	File::File()
		: m_baseDir(GetBaseDirPtr().release()), m_dir(m_baseDir) {}

	File &File::Get()
	{
		static File fileSys;
		return fileSys;
	}

	const std::string &File::GetBaseDir() const
	{
		return m_baseDir;
	}

	std::unique_ptr<char, void (*)(char *)> File::GetBaseDirPtr() const
	{
		return {SDL_GetBasePath(), [](char *p)
				{
					if (p)
						SDL_free(p);
					p = nullptr;
				}};
	}

	const std::string &File::GetDir() const
	{
		return m_dir;
	}

	void File::SetDir(const std::string &path)
	{
		m_dir = path;
	}
} // namespace Pazu

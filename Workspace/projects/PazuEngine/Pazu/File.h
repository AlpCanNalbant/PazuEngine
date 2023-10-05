// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <filesystem>
#include "Stream.h"

namespace Pazu
{
	class File : public INonCopyable
	{
	public:
		static File &Get();
		template <typename T = Stream>
		std::unique_ptr<T> Open(const std::string &path);
		const std::string &GetBaseDir() const;
		const std::string &GetDir() const;
		void SetDir(const std::string &path);

		static constexpr char Separator = std::filesystem::path::preferred_separator;

	private:
		File();
		std::unique_ptr<char, void (*)(char *)> GetBaseDirPtr() const;

		const std::string m_baseDir;
		std::string m_dir;
	};
} // namespace Pazu
#include "File.inl"

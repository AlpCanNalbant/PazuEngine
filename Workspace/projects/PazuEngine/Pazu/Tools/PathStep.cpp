// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../File.h"
#include "PathStep.h"

namespace Pazu
{
	PathStep::PathStep()
		: m_separator(File::Separator) {}

	PathStep::PathStep(const std::string &source, const char separator)
	{
		SetSource(source, separator);
	}

	PathStep &PathStep::Forward(const std::string &folderName)
	{
		if (!m_source.ends_with(m_separator))
			m_source += m_separator;
		m_source += folderName + m_separator;
		return *this;
	}

	PathStep &PathStep::Forward(std::initializer_list<std::string> folderNames)
	{
		for (auto &folderName : folderNames)
			Forward(folderName);
		return *this;
	}

	PathStep &PathStep::Backward()
	{
		if (m_source.ends_with(m_separator))
			m_source.erase(m_source.end() - 1);
		m_source.erase(m_source.find_last_of(m_separator) + 1, m_source.size());
		return *this;
	}

	PathStep &PathStep::Backward(const unsigned int backCount)
	{
		for (unsigned int i = 0; i < backCount; ++i)
			Backward();
		return *this;
	}

	char PathStep::FindSeparator(const std::initializer_list<char> separators) const
	{
		const auto separatorsStr = std::string(separators.begin(), separators.end());
		if (const auto pos = m_source.find_first_of(separatorsStr); pos != std::string::npos)
			return m_source[pos];
		return File::Separator;
	}

	const std::string &PathStep::GetSource() const
	{
		return m_source;
	}

	char PathStep::GetSeparator() const
	{
		return m_separator;
	}

	PathStep &PathStep::SetSource(const std::string &source, const char separator)
	{
		m_source = source;
		if (separator == '\0')
			m_separator = FindSeparator();
		else
			SetSeparator(separator);
		return *this;
	}

	PathStep &PathStep::SetSeparator(const char separator)
	{
		std::replace(m_source.begin(), m_source.end(), m_separator, separator);
		m_separator = separator;
		return *this;
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	class PathStep
	{
	public:
		PathStep();
		PathStep(const std::string &source, const char separator = '\0');
		PathStep &Forward(const std::string &folderName);
		PathStep &Forward(std::initializer_list<std::string> folderNames);
		PathStep &Backward();
		PathStep &Backward(const unsigned int backCount);
		const std::string &GetSource() const;
		char GetSeparator() const;
		PathStep &SetSource(const std::string &source, const char separator = '\0');
		PathStep &SetSeparator(const char separator);

	private:
		char FindSeparator(std::initializer_list<char> separators = {{'\\'}, {'/'}}) const;

		std::string m_source;
		char m_separator;
	};
} // namespace Pazu

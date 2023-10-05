// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	BasicStream<T>::BasicStream(std::basic_ofstream<T> ofstream, std::basic_ifstream<T> ifstream)
		: m_ofstream(std::move(ofstream)), m_ifstream(std::move(ifstream)) {}

	template <typename T>
	void BasicStream<T>::Write(const std::basic_string<T> &string)
	{
		m_ofstream << string << std::flush;
		m_ifstream.clear();
	}

	template <typename T>
	void BasicStream<T>::WriteLine(const std::basic_string<T> &line)
	{
		m_ofstream << line << std::endl;
		m_ifstream.clear();
	}

	template <typename T>
	std::basic_string<T> BasicStream<T>::Read()
	{
		std::basic_string<T> string;
		for (T c; m_ifstream.get(c);)
			string += c;
		return string;
	}

	template <typename T>
	std::basic_string<T> BasicStream<T>::ReadLine()
	{
		std::basic_string<T> line;
		std::getline(m_ifstream, line);
		return line;
	}
}

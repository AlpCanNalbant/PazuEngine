// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <fstream>

namespace Pazu
{
	template <typename T>
	class BasicStream : public INonCopyable
	{
		friend std::unique_ptr<BasicStream> std::make_unique<BasicStream>(std::basic_ofstream<T> &&ofstream, std::basic_ifstream<T> &&ifstream);

	public:
		void Write(const std::basic_string<T> &string);
		void WriteLine(const std::basic_string<T> &line);
		std::basic_string<T> Read();
		std::basic_string<T> ReadLine();

		using Type = T;

	private:
		BasicStream(std::basic_ofstream<T> ofstream, std::basic_ifstream<T> ifstream);

		std::basic_ofstream<T> m_ofstream;
		std::basic_ifstream<T> m_ifstream;
	};
	using Stream = BasicStream<char>;
	using WStream = BasicStream<wchar_t>;
}
#include "Stream.inl"

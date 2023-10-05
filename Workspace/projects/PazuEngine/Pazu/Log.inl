// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	std::unique_ptr<WStream> BasicLog<T>::m_stream;

	template <typename T>
	BasicLog<T>::BasicLog()
	{
		m_stream = File::Get().Open<WStream>("Log.txt");
	}

	template <typename T>
	BasicLog<T> &BasicLog<T>::Get()
	{
		static BasicLog<T> log;
		return log;
	}

	template <typename T>
	template <LogMode Mode, typename TRes>
	TRes BasicLog<T>::Print(const std::basic_string<T> &message)
	{
		if constexpr (Mode != LogMode::None)
		{
			if constexpr (std::is_same_v<T, char>)
			{
				if (m_stream)
					m_stream->WriteLine(ToWide(ToString(GetNow()) + ToString(Mode) + message));
				if constexpr (Mode != LogMode::Error)
					std::cout << ToString(GetNow()) << ToString(Mode);
				else
					std::cerr << ToString(GetNow()) << ToString(Mode);
			}
			else if constexpr (std::is_same_v<T, wchar_t>)
			{
				if (m_stream)
					m_stream->WriteLine(ToString(GetNow()) + ToString(Mode) + message);
				if constexpr (Mode != LogMode::Error)
					std::wcout << ToString(GetNow()) << ToString(Mode);
				else
					std::wcerr << ToString(GetNow()) << ToString(Mode);
			}
		}
		if constexpr (std::is_same_v<T, char>)
		{
			if constexpr (Mode != LogMode::Error)
				std::cout << message << '\n';
			else
				std::cerr << message << '\n';
		}
		else if constexpr (std::is_same_v<T, wchar_t>)
		{
			if constexpr (Mode != LogMode::Error)
				std::wcout << message << L'\n';
			else
				std::wcerr << message << L'\n';
		}
		if constexpr (Mode == LogMode::Fatal)
			throw std::runtime_error("");
		return TRes();
	}

	template <typename T>
	template <LogMode Mode, typename TRes>
	const TRes &BasicLog<T>::Print(const std::basic_string<T> &message, const TRes &result)
	{
		Print(message);
		return result;
	}

	template <typename T>
	std::basic_string<T> BasicLog<T>::ToString(const LogMode mode) const
	{
		const auto name = std::string(magic_enum::enum_name(mode));
		if constexpr (std::is_same_v<T, char>)
			return name + ": ";
		else if constexpr (std::is_same_v<T, wchar_t>)
			return std::wstring(name.cbegin(), name.cend()) + L": ";
	}

	template <typename T>
	std::basic_string<T> BasicLog<T>::ToString(const tm &currentTime) const
	{
		if constexpr (std::is_same_v<T, char>)
			return '[' + std::to_string(currentTime.tm_hour) + ':' + std::to_string(currentTime.tm_min) + ':' + std::to_string(currentTime.tm_sec) + "] ";
		else if constexpr (std::is_same_v<T, wchar_t>)
			return L'[' + std::to_wstring(currentTime.tm_hour) + L':' + std::to_wstring(currentTime.tm_min) + L':' + std::to_wstring(currentTime.tm_sec) + L"] ";
	}

#if defined(_WIN32)
	template <typename T>
	std::wstring BasicLog<T>::ToString(const HRESULT hResult) const
	{
		const _com_error comError(hResult);
		return L"HRESULT hata kodu: " + WLog::Get().ToHex(static_cast<unsigned int>(hResult)) + L" HRESULT hata mesaji: " + comError.ErrorMessage();
	}
#endif

	template <typename T>
	const tm &BasicLog<T>::GetNow() const
	{
		const std::time_t t = std::time(nullptr);
		return *std::localtime(&t);
	}

	template <typename T>
	template <typename TNum>
	std::basic_string<T> BasicLog<T>::ToHex(const TNum number) const
	{
		std::basic_stringstream<T> stream;
		stream << "0x" << std::setfill<T>('0') << std::setw(sizeof(T) * 2) << std::uppercase << std::hex << number;
		if constexpr (std::is_same_v<T, wchar_t>)
		{
			auto hexStr = stream.str();
			for (auto pos = std::find(hexStr.cbegin(), hexStr.cend(), '.'); pos != hexStr.cend(); pos = std::find(pos, hexStr.cend(), '.'))
				hexStr.erase(pos);
			stream.str(hexStr);
		}
		return stream.str();
	}

	template <typename T>
	std::wstring BasicLog<T>::ToWide(const std::string string) const
	{
		return {string.cbegin(), string.cend()};
	}

	template <typename T>
	const std::unique_ptr<WStream> &BasicLog<T>::GetStream() const
	{
		return m_stream;
	}

	template <typename T>
	void BasicLog<T>::SetStream(std::unique_ptr<WStream> stream)
	{
		m_stream = std::move(stream);
	}
}

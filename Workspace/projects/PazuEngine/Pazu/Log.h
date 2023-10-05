// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "LogMode.h"

namespace Pazu
{
	template <typename T>
	class BasicLog : public INonCopyable
	{
	public:
		static BasicLog<T> &Get();
		template <LogMode Mode, typename TRes = void>
		TRes Print(const std::basic_string<T> &message);
		template <LogMode Mode, typename TRes>
		const TRes &Print(const std::basic_string<T> &message, const TRes &result);
		std::basic_string<T> ToString(const LogMode mode) const;
		std::basic_string<T> ToString(const tm &currentTime) const;
		template <typename TNum>
		std::basic_string<T> ToHex(const TNum number) const;
		std::wstring ToWide(const std::string string) const;
#if defined(_WIN32)
		std::wstring ToString(const HRESULT hResult) const;
#endif
		const tm &GetNow() const;
		const std::unique_ptr<WStream> &GetStream() const;
		void SetStream(std::unique_ptr<WStream> stream);

	private:
		BasicLog();

		static std::unique_ptr<WStream> m_stream;
	};
	using Log = BasicLog<char>;
	using WLog = BasicLog<wchar_t>;
} // namespace Pazu
#include "Log.inl"

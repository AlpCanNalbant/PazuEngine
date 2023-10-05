// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	enum class LogMode
	{
		None,
		Info,
		Error,
		Fatal
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::LogMode>
	{
		static constexpr int min{static_cast<int>(Pazu::LogMode::None)};  // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::LogMode::Fatal)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

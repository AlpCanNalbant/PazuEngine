// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	enum class SystemEventState : unsigned int
	{
		None = 0,
		Quit = SDL_QUIT
	};
} // namespace Pazu

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::SystemEventState>
	{
		static constexpr int min{static_cast<int>(Pazu::SystemEventState::None)}; // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::SystemEventState::Quit)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu::Graphics
{
	enum class BufferUsage
	{
		Static,
		Dynamic
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::BufferUsage>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::BufferUsage::Static)};  // Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::BufferUsage::Dynamic)}; // Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

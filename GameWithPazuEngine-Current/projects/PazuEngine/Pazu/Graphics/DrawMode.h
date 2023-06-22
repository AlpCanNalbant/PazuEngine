#pragma once

namespace Pazu::Graphics
{
	enum class DrawMode
	{
		PointList,
		LineList,
		LineStrip,
		TriangleList,
		TriangleStrip,
		LineListAdj,
		LineStripAdj,
		TriangleListAdj,
		TriangleStripAdj
	};
}

namespace magic_enum::customize
{
	template <>
	struct enum_range<Pazu::Graphics::DrawMode>
	{
		static constexpr int min{static_cast<int>(Pazu::Graphics::DrawMode::PointList)};				//Default: 0 Minimum: -32,768
		static constexpr int max{static_cast<int>(Pazu::Graphics::DrawMode::TriangleStripAdj)}; //Default: 256 Maximum: 32,767
	};
} // namespace magic_enum::customize

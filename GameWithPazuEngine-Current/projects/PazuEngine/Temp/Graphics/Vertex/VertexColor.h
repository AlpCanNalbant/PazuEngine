#pragma once
#include "../../Math/Color.h"

namespace Pazu
{
	template <typename T>
	class VertexColor
	{
	public:
		VertexColor() noexcept = default;
		VertexColor(const std::array<T, 4> &colorData) noexcept;
		VertexColor(const Color &color) noexcept;
		VertexColor(const VertexColor &other) noexcept = default;
		VertexColor(VertexColor &&temp) noexcept = default;
		virtual ~VertexColor() noexcept = 0;
		VertexColor &operator=(const VertexColor &other) noexcept = default;
		VertexColor &operator=(VertexColor &&temp) noexcept = default;
		Color GetColor() const noexcept;
		void SetColor(const Color &color) noexcept;

	protected:
		std::array<T, 4> m_colorData;
	};
} // namespace Pazu
#include "VertexColor.inl"

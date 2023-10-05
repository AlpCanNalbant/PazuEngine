// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	VertexPosition<T>::VertexPosition(const std::array<T, 3> &position) noexcept
		: m_position(position) {}
} // namespace Pazu

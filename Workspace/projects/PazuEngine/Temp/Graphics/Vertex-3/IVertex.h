#pragma once

namespace Pazu
{
	template <typename T, std::size_t Size>
	struct IVertex
	{
	public:
		virtual ~IVertex() noexcept = default;
		virtual const std::array<T, Size> &GetData() const noexcept = 0;
	};
}

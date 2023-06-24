#pragma once
#include <set>
#include "IVertex.h"

namespace Pazu
{
	class VertexSet
	{
	public:
		template <typename T, std::size_t Size>
		void Add(const IVertex<T, Size> &vertex) noexcept;
		const std::vector<std::shared_ptr<void>> &GetData() const noexcept;
		unsigned int GetStride() const noexcept;

	private:
		std::set<VertexType> m_types;
		std::vector<std::shared_ptr<void>> m_data;
		unsigned int m_stride{0};
	};
}
#include "VertexSet.inl"

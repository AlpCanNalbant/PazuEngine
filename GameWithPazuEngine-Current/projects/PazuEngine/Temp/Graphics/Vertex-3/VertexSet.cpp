#include "VertexSet.h"
using namespace magic_enum;

namespace Pazu
{
	const std::vector<std::shared_ptr<void>> &VertexSet::GetData() const noexcept
	{
		return m_data;
	}

	unsigned int VertexSet::GetStride() const noexcept
	{
		return m_stride;
	}
}

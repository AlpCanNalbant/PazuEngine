namespace Pazu
{
	template <typename T, std::size_t Size>
	void VertexSet::Add(const IVertex<T, Size> &vertex) noexcept
	{
		const auto type = vertex.GetType();
		if (m_types.contains(type))
			return;
		m_types.emplace(type);
		for (const auto d : vertex.GetData())
			m_data.emplace_back(std::make_shared<T>(d));
		m_stride += vertex.GetByteWidth();
	}
}

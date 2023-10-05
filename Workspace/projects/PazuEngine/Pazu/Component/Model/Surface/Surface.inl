// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename TVertex, typename TIndex>
	Surface<TVertex, TIndex>::Surface(const std::shared_ptr<Graphics::VertexBuffer<TVertex>> &vertexBuffer, const std::shared_ptr<Graphics::IndexBuffer<TIndex>> &indexBuffer, const std::shared_ptr<Material> &material)
		: m_material(material), m_vertexBuffer(vertexBuffer), m_indexBuffer(indexBuffer) {}

	template <typename TVertex, typename TIndex>
	Surface<TVertex, TIndex>::Surface(const Surface &other)
		: m_material(std::make_shared<Material>(*other.m_material)), m_vertexBuffer(other.m_vertexBuffer), m_indexBuffer(other.m_indexBuffer) {}

	template <typename TVertex, typename TIndex>
	Surface<TVertex, TIndex> &Surface<TVertex, TIndex>::operator=(const Surface &other)
	{
		m_material = std::make_shared<Material>(*other.m_material);
		m_vertexBuffer = other.m_vertexBuffer;
		m_indexBuffer = other.m_indexBuffer;
	}

	template <typename TVertex, typename TIndex>
	const std::shared_ptr<Material> &Surface<TVertex, TIndex>::GetMaterial() const
	{
		return m_material;
	}

	template <typename TVertex, typename TIndex>
	const Graphics::VertexBuffer<TVertex> &Surface<TVertex, TIndex>::GetVertexBuffer() const
	{
		return *m_vertexBuffer;
	}

	template <typename TVertex, typename TIndex>
	const Graphics::IndexBuffer<TIndex> &Surface<TVertex, TIndex>::GetIndexBuffer() const
	{
		return *m_indexBuffer;
	}

	template <typename TVertex, typename TIndex>
	void Surface<TVertex, TIndex>::SetMaterial(const std::shared_ptr<Material> &material)
	{
		m_material = material;
	}
} // namespace Pazu

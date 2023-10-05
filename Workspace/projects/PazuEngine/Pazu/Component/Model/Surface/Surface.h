// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Graphics/Buffer/BufferUsage.h"
#include "../../../Graphics/Buffer/VertexBuffer.h"
#include "../../../Graphics/Buffer/IndexBuffer.h"
#include "Material.h"

namespace Pazu
{
	template <typename TVertex, typename TIndex>
	class Surface
	{
	public:
		Surface(const std::shared_ptr<Graphics::VertexBuffer<TVertex>> &vertexBuffer, const std::shared_ptr<Graphics::IndexBuffer<TIndex>> &indexBuffer, const std::shared_ptr<Material> &material = std::make_shared<Material>());
		Surface(const Surface &other);
		Surface(Surface &&other) = default;
		~Surface() = default;
		Surface &operator=(const Surface &other);
		Surface &operator=(Surface &&other) = default;
		const std::shared_ptr<Material> &GetMaterial() const;
		const Graphics::VertexBuffer<TVertex> &GetVertexBuffer() const;
		const Graphics::IndexBuffer<TIndex> &GetIndexBuffer() const;
		void SetMaterial(const std::shared_ptr<Material> &material);

		using Vertex = TVertex;
		using Index = TIndex;

	protected:
		std::shared_ptr<Material> m_material;
		std::shared_ptr<Graphics::VertexBuffer<TVertex>> m_vertexBuffer;
		std::shared_ptr<Graphics::IndexBuffer<TIndex>> m_indexBuffer;
	};
} // namespace Pazu
#include "Surface.inl"

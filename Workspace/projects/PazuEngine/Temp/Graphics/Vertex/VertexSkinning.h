// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../Math/Vector4.h"
#include "IVertex.h"

namespace Pazu
{
	template <typename TWeights, typename TIndices>
	class VertexSkinning : public IVertex
	{
	public:
		VertexSkinning() noexcept = default;
		VertexSkinning(const std::array<TWeights, 4> &textureData, const std::array<TIndices, 4> &indices) noexcept;
		VertexSkinning(const Vector4 &weights, const std::array<TIndices, 4> &indices) noexcept;
		VertexSkinning(const VertexSkinning &other) noexcept = default;
		VertexSkinning(VertexSkinning &&temp) noexcept = default;
		virtual ~VertexSkinning() noexcept = 0;
		VertexSkinning &operator=(const VertexSkinning &other) noexcept = default;
		VertexSkinning &operator=(VertexSkinning &&temp) noexcept = default;
		Vector4 GetWeights() const noexcept;
		std::array<TIndices, 4> GetIndices() const noexcept;
		void SetBlendWeights(const Vector4 &weights) noexcept;
		void SetBlendIndices(const std::array<TIndices, 4> &indices) noexcept;

	protected:
		std::array<TWeights, 4> m_weightsData;
		std::array<TIndices, 4> m_indicesData;
	};
}

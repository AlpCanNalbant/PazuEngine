// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TransformBase.h"

namespace Pazu
{
	class TransformScale : public virtual TransformBase
	{
	public:
		void CalculateScale();
		void Scale(const Vector3 &scale);
		void Scale(const float width, const float height, const float depth);
		void Scale(const float scale);
		const Vector3 &GetScale() const;
		float GetWidth() const;
		float GetHeight() const;
		float GetDepth() const;
		void SetScale(const Vector3 &scale);
		void SetScale(const float width, const float height, const float depth);
		void SetScale(const float scale);
		void SetWidth(const float width);
		void SetHeight(const float height);
		void SetDepth(const float depth);

	protected:
		Vector3 m_scale{Vector3::One};
	};
} // namespace Pazu

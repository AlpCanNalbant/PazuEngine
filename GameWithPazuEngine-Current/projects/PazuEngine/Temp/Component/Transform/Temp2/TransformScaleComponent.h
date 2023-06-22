#pragma once
#include "TransformComponent.h"

namespace Pazu
{
	class TransformScaleComponent : public virtual TransformComponent
	{
	public:
		Matrix CreateScale() noexcept;
		void Scale(const Vector3 &scale) noexcept;
		void Scale(const float width, const float height, const float depth) noexcept;
		void Scale(const float scale) noexcept;
		const Vector3 &GetScale() const noexcept;
		float GetWidth() const noexcept;
		float GetHeight() const noexcept;
		float GetDepth() const noexcept;
		void SetScale(const Vector3 &scale) noexcept;
		void SetScale(const float width, const float height, const float depth) noexcept;
		void SetScale(const float scale) noexcept;
		void SetWidth(const float width) noexcept;
		void SetHeight(const float height) noexcept;
		void SetDepth(const float depth) noexcept;

	protected:
		Vector3 m_scale{Vector3::One};
	};
} // namespace Pazu

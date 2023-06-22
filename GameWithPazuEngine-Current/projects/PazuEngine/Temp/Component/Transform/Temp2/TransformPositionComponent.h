#pragma once
#include "TransformComponent.h"

namespace Pazu
{
	class TransformPositionComponent : public virtual TransformComponent
	{
	public:
		Matrix CreateTranslation() noexcept;
		void Translate(const Vector3 &position) noexcept;
		void Translate(const float x, const float y, const float z) noexcept;
		const Vector3 &GetPosition() const noexcept;
		float GetX() const noexcept;
		float GetY() const noexcept;
		float GetZ() const noexcept;
		void SetPosition(const Vector3 &position) noexcept;
		void SetPosition(const float x, const float y, const float z) noexcept;
		void SetX(const float x) noexcept;
		void SetY(const float y) noexcept;
		void SetZ(const float z) noexcept;

	protected:
		Vector3 m_position;
	};
} // namespace Pazu

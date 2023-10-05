// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TransformBase.h"

namespace Pazu
{
	class TransformPosition : public virtual TransformBase
	{
	public:
		void CalculateTranslation();
		void Translate(const Vector3 &position);
		void Translate(const float x, const float y, const float z);
		const Vector3 &GetPosition() const;
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		void SetPosition(const Vector3 &position, const bool global = false);
		void SetPosition(const float x, const float y, const float z, const bool global = false);
		void SetX(const float x, const bool global = false);
		void SetY(const float y, const bool global = false);
		void SetZ(const float z, const bool global = false);

	protected:
		Quaternion m_quaternion;
		Vector3 m_position;
	};
} // namespace Pazu

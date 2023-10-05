// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "TransformPosition.h"
#include "TransformRotation.h"

namespace Pazu
{
	class TransformPositionRotation : public TransformPosition, public TransformRotation
	{
	public:
		Matrix CreateLookAt() noexcept;
		void Translate(const Vector3 &position, const bool global = false) noexcept;
		void Translate(const float x, const float y, const float z, const bool global = false) noexcept;
		void SetPosition(const Vector3 &position, const bool global = false) noexcept;
		void SetPosition(const float x, const float y, const float z, const bool global = false) noexcept;
		void SetX(const float x, const bool global = false) noexcept;
		void SetY(const float y, const bool global = false) noexcept;
		void SetZ(const float z, const bool global = false) noexcept;
	};
} // namespace Pazu

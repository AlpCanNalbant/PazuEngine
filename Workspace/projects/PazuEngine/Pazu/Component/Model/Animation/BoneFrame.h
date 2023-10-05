// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../../../Math/Quaternion.h"
#include "../../../Math/Vector3.h"

namespace Pazu
{
	struct BoneFrame
	{
		BoneFrame() = default;
		BoneFrame(const Vector3 &position, const Quaternion &rotation, const Vector3 &scale);

		Vector3 position;
		Quaternion rotation;
		Vector3 scale;
	};
}

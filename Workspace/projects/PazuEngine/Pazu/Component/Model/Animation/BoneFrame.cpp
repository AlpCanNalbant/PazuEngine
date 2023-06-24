#include "BoneFrame.h"

namespace Pazu
{
	BoneFrame::BoneFrame(const Vector3 &position, const Quaternion &rotation, const Vector3 &scale)
			: position(position), rotation(rotation), scale(scale) {}
}

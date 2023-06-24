#pragma once
#include "TransformPositionRotationScaleComponent.h"
#include "TransformPositionScaleComponent.h"
#include "TransformRotationScaleComponent.h"
#include "TransformHolder.h"

namespace Pazu
{
	using TTransformPositionHolder = TransformHolder<TransformPositionComponent>;
	using TTransformRotationHolder = TransformHolder<TransformRotationComponent>;
	using TTransformScaleHolder = TransformHolder<TransformScaleComponent>;
	using TTransformPositionRotationHolder = TransformHolder<TransformPositionRotationComponent>;
	using TTransformPositionScaleHolder = TransformHolder<TransformPositionScaleComponent>;
	using TTransformPositionRotationScaleHolder = TransformHolder<TransformPositionRotationScaleComponent>;
	using TTransformRotationScaleHolder = TransformHolder<TransformRotationScaleComponent>;
}

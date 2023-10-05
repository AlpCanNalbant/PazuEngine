// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Mathf.h"

namespace Pazu
{
	float Mathf::Clamp(const float value, const float min, const float max)
	{
		return std::clamp(value, min, max);
	}

	float Mathf::Clamp01(const float value)
	{
		return std::clamp(value, 0.f, 1.f);
	}

	float Mathf::Mod(const float x, const float y)
	{
		return std::fmodf(x, y);
	}

	float Mathf::Sin(const float f)
	{
		return std::sinf(f);
	}

	float Mathf::Cos(const float f)
	{
		return std::cosf(f);
	}

	float Mathf::Tan(const float f)
	{
		return std::tanf(f);
	}

	float Mathf::Asin(const float f)
	{
		return std::asinf(f);
	}

	float Mathf::Acos(const float f)
	{
		return std::acosf(f);
	}

	float Mathf::Atan(const float f)
	{
		return std::atanf(f);
	}

	float Mathf::Atan2(const float y, const float x)
	{
		return std::atan2f(y, x);
	}

	float Mathf::Sqrt(const float f)
	{
		return std::sqrtf(f);
	}

	float Mathf::Abs(const float f)
	{
		return std::fabsf(f);
	}

	float Mathf::Min(const float a, const float b)
	{
		return std::fminf(a, b);
	}

	float Mathf::Min(const std::initializer_list<float> values)
	{
		return std::min(values);
	}

	float Mathf::Max(const float a, const float b)
	{
		return std::fmaxf(a, b);
	}

	float Mathf::Max(const std::initializer_list<float> values)
	{
		return std::max(values);
	}

	float Mathf::Pow(const float f, const float p)
	{
		return std::powf(f, p);
	}

	float Mathf::Exp(const float power)
	{
		return std::expf(power);
	}

	float Mathf::Log(const float f)
	{
		return std::logf(f);
	}

	float Mathf::Log10(const float f)
	{
		return std::log10f(f);
	}

	float Mathf::Ceil(const float f)
	{
		return std::ceilf(f);
	}

	float Mathf::Floor(const float f)
	{
		return std::floorf(f);
	}

	float Mathf::Round(const float f)
	{
		return std::roundf(f);
	}

	float Mathf::Sign(const float f)
	{
		return f >= 0.f ? 1.f : -1.f;
	}

	float Mathf::Lerp(const float a, const float b, const float t)
	{
		return a + (b - a) * Clamp01(t);
	}

	float Mathf::LerpUnclamped(const float a, const float b, const float t)
	{
		return a + (b - a) * t;
	}

	float Mathf::LerpAngle(const float a, const float b, const float t)
	{
		auto delta = Repeat((b - a), 360.f);
		if (delta > 180.f)
			delta -= 360.f;
		return a + delta * Clamp01(t);
	}

	float Mathf::MoveTowards(const float current, const float target, const float maxDelta)
	{
		if (Abs(target - current) <= maxDelta)
			return target;
		return current + Sign(target - current) * maxDelta;
	}

	float Mathf::MoveTowardsAngle(const float current, float target, const float maxDelta)
	{
		auto deltaAngle = DeltaAngle(current, target);
		if (-maxDelta < deltaAngle && deltaAngle < maxDelta)
			return target;
		target = current + deltaAngle;
		return MoveTowards(current, target, maxDelta);
	}

	float Mathf::SmoothStep(const float from, const float to, float t)
	{
		t = Clamp01(t);
		t = -2.f * t * t * t + 3.f * t * t;
		return to * t + from * (1.f - t);
	}

	bool Mathf::Approximately(const float a, const float b, const float precision)
	{
		return Abs(b - a) < Max(precision * Max(Abs(a), Abs(b)), Epsilon * 8.f);
	}

	float Mathf::SmoothDamp(const float current, float target, float &currentVelocity, float smoothTime, const float deltaTime, const float maxSpeed)
	{
		smoothTime = Max(0.0001f, smoothTime);
		const auto omega = 2.f / smoothTime;
		const auto x = omega * deltaTime;
		const auto exp = 1.f / (1.f + x + 0.48f * x * x + 0.235f * x * x * x);
		auto change = current - target;
		const auto originalTo = target;

		const auto maxChange = maxSpeed * smoothTime;
		change = Clamp(change, -maxChange, maxChange);
		target = current - change;

		const auto temp = (currentVelocity + omega * change) * deltaTime;
		currentVelocity = (currentVelocity - omega * temp) * exp;
		auto output = target + (change + temp) * exp;

		if (originalTo - current > 0.f == output > originalTo)
		{
			output = originalTo;
			currentVelocity = (output - originalTo) / deltaTime;
		}
		return output;
	}

	float Mathf::SmoothDampAngle(const float current, float target, float &currentVelocity, const float smoothTime, const float deltaTime, const float maxSpeed)
	{
		target = current + DeltaAngle(current, target);
		return SmoothDamp(current, target, currentVelocity, smoothTime, deltaTime, maxSpeed);
	}

	float Mathf::PingPong(float t, const float lenght)
	{
		t = Repeat(t, lenght * 2.f);
		return lenght - Abs(t - lenght);
	}

	float Mathf::InverseLerp(const float a, const float b, const float value)
	{
		if (a != b)
			return Clamp01((value - a) / (b - a));
		return 0.f;
	}

	float Mathf::Repeat(const float t, const float lenght)
	{
		return Clamp(t - Floor(t / lenght) * lenght, 0.f, lenght);
	}

	float Mathf::DeltaAngle(const float current, const float target)
	{
		auto delta = Repeat(target - current, 360.f);
		if (delta > 180.f)
			delta -= 360.f;
		return delta;
	}
}

#pragma once
#include <initializer_list>
#include <numeric>

namespace Pazu
{
	class Mathf : public INonCreatable
	{
	public:
		static float Clamp(const float value, const float min, const float max);
		static float Clamp01(const float value);
		static constexpr float ToRadians(const float degrees);
		static constexpr float ToDegrees(const float radians);
		static float Mod(const float x, const float y);
		static float Sin(const float f);
		static float Cos(const float f);
		static float Tan(const float f);
		static float Asin(const float f);
		static float Acos(const float f);
		static float Atan(const float f);
		static float Atan2(const float y, const float x);
		static float Sqrt(const float f);
		static float Abs(const float f);
		static float Min(const float a, const float b);
		static float Min(const std::initializer_list<float> values);
		static float Max(const float a, const float b);
		static float Max(const std::initializer_list<float> values);
		static float Pow(const float f, const float p);
		static float Exp(const float power);
		static float Log(const float f);
		static float Log10(const float f);
		static float Ceil(const float f);
		static float Floor(const float f);
		static float Round(const float f);
		static float Sign(const float f);
		static float Lerp(const float a, const float b, const float t);
		static float LerpUnclamped(const float a, const float b, const float t);
		static float LerpAngle(const float a, const float b, const float t);
		static float MoveTowards(const float current, const float target, const float maxDelta);
		static float MoveTowardsAngle(const float current, float target, const float maxDelta);
		static float SmoothStep(const float from, const float to, float t);
		static bool Approximately(const float a, const float b, const float precision = 0.000001f);
		static float SmoothDamp(const float current, float target, float &currentVelocity, float smoothTime, const float deltaTime, const float maxSpeed = Infinity);
		static float SmoothDampAngle(const float current, float target, float &currentVelocity, const float smoothTime, const float deltaTime, const float maxSpeed = Infinity);
		static float PingPong(float t, const float lenght);
		static float InverseLerp(const float a, const float b, const float value);
		static float Repeat(const float t, const float lenght);
		static float DeltaAngle(const float current, const float target);

		static constexpr float
				Pi{3.141592654f},
				TwoPi{6.283185307f},
				PiOver2{1.570796327f},
				PiOver4{0.785398163f};
		static constexpr float Infinity = std::numeric_limits<float>::infinity();
		static constexpr float Epsilon = std::numeric_limits<float>::epsilon();
	};
} // namespace Pazu
#include "Mathf.inl"

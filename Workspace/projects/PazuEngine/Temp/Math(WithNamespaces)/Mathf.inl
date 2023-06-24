namespace Pazu::Math
{
	constexpr float Mathf::ToRadians(const float degrees) noexcept
	{
		return degrees * (Pi / 180.f);
	}

	constexpr float Mathf::ToDegrees(const float radians) noexcept
	{
		return radians * (180.f / Pi);
	}
} // namespace Pazu

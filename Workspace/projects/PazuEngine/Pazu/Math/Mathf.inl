namespace Pazu
{
	constexpr float Mathf::ToRadians(const float degrees)
	{
		return degrees * (Pi / 180.f);
	}

	constexpr float Mathf::ToDegrees(const float radians)
	{
		return radians * (180.f / Pi);
	}
} // namespace Pazu

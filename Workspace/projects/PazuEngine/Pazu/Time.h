#pragma once
#include <chrono>

namespace Pazu
{
	class Time
	{
	public:
		Time();
		float GetDelta() const;
		int GetFps() const;
		void Update();
		bool CalculateFps();

	private:
		std::chrono::steady_clock::time_point m_last;
		float m_delta{0.f};
		float m_elapsedTime{0.f};
		int m_fps{0};
		int m_lastFps{0};
	};
}

#include "Time.h"
using namespace std::chrono;

namespace Pazu
{
	Time::Time()
			: m_last(steady_clock::now()) {}

	float Time::GetDelta() const
	{
		return m_delta;
	}

	int Time::GetFps() const
	{
		return m_lastFps;
	}

	void Time::Update()
	{
		const auto old = m_last;
		m_last = steady_clock::now();
		m_delta = duration_cast<duration<float>>(m_last - old).count();
	}

	bool Time::CalculateFps()
	{
		m_elapsedTime += m_delta;
		if (m_elapsedTime >= 1.f)
		{
			m_lastFps = m_fps;
			m_fps = 0;
			m_elapsedTime = 0.f;
			return true;
		}
		++m_fps;
		return false;
	}
}

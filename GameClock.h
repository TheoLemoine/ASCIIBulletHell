#pragma once
#include <Windows.h>

class GameClock {

public:
	static const int MULT_SEC = 1000000; // get time in seconds
	static const int MULT_MILISEC = 1000; // get time in miliseconds
	static const int MULT_MICROSEC = 1; // get time in microseconds

	GameClock()
	{
		QueryPerformanceCounter(&m_startTime);
		m_lastCalledTime = m_startTime;
		QueryPerformanceFrequency(&m_freqency);
	}

	void SetMultiplier(int muliplier)
	{
		m_timeMultiplier = muliplier;
	}

	float GetElapsedTime()
	{
		LARGE_INTEGER currentTime;
		QueryPerformanceCounter(&currentTime);

		return (float)(currentTime.QuadPart - m_startTime.QuadPart) / m_timeMultiplier;
	}

	float GetElapsedTimeSinceLastCall()
	{
		LARGE_INTEGER currentTime;
		QueryPerformanceCounter(&currentTime);

		float elapsedTime = (float)(currentTime.QuadPart - m_lastCalledTime.QuadPart) / m_timeMultiplier;

		m_lastCalledTime = currentTime;

		return elapsedTime;
	}

private:
	LARGE_INTEGER m_startTime;
	LARGE_INTEGER m_freqency;
	LARGE_INTEGER m_lastCalledTime;
	int m_timeMultiplier = 0;

};
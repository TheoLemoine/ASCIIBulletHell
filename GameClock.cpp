#include "GameClock.h"
#include <Windows.h>


GameClock::GameClock()
{
	QueryPerformanceCounter(&m_startTime);
	m_lastCalledTime = m_startTime;
	QueryPerformanceFrequency(&m_freqency);
}

void GameClock::SetMultiplier(int muliplier)
{
	m_timeMultiplier = muliplier;
}

float GameClock::GetElapsedTime()
{
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);

	return (float)(currentTime.QuadPart - m_startTime.QuadPart) / m_timeMultiplier;
}

float GameClock::GetElapsedTimeSinceLastCall()
{
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);

	float elapsedTime = (float)(currentTime.QuadPart - m_lastCalledTime.QuadPart) / m_timeMultiplier;

	m_lastCalledTime = currentTime;

	return elapsedTime;
}
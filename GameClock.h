#pragma once
#include <Windows.h>


class GameClock {

public:
	static constexpr int MULT_SEC = 1000000; // get time in seconds
	static constexpr int MULT_MILISEC = 1000; // get time in miliseconds
	static constexpr int MULT_MICROSEC = 1; // get time in microseconds

	GameClock();

	void SetMultiplier(int muliplier);

	float GetElapsedTime();

	float GetElapsedTimeSinceLastCall();

private:
	LARGE_INTEGER m_startTime;
	LARGE_INTEGER m_freqency;
	LARGE_INTEGER m_lastCalledTime;
	int m_timeMultiplier = 0;

};
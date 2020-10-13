#pragma once
#include <Windows.h>
#include <utility>
#include <vector>
#include <queue>
#include <thread>
#include <condition_variable>

class SoundSystem
{
public:
	SoundSystem();
	~SoundSystem();
	void AsyncBeep(DWORD freq, DWORD duration);

private:
	std::vector<std::thread*> m_threadPool;
	std::queue<std::pair<DWORD, DWORD>> m_beepsToPlay;
	std::condition_variable m_cv;
	std::mutex m_mutex;
	unsigned int m_nbAvailableThreads;

	void startBeepingThread();
};

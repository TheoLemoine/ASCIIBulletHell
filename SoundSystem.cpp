// header file
#include "SoundSystem.h"

#include <Windows.h>
#include <utility>
#include <vector>
#include <queue>
#include <thread>
#include <condition_variable>


SoundSystem::SoundSystem() 
{ 
	m_nbAvailableThreads = 0;

	auto wrkr = new std::thread(&SoundSystem::startBeepingThread, this);
	m_threadPool.push_back(wrkr);
}

SoundSystem::~SoundSystem() {
	auto end_itr = m_threadPool.end();
	for (auto itr = m_threadPool.begin(); itr != end_itr; ++itr) 
	{
		delete (*itr);
	}
}

void SoundSystem::AsyncBeep(DWORD freq, DWORD duration) 
{
	m_beepsToPlay.push(std::pair<DWORD, DWORD>(freq, duration));
	m_cv.notify_one();

	// always have a thread ready
	if(m_nbAvailableThreads == 0)
	{
		auto wrkr = new std::thread(&SoundSystem::startBeepingThread, this);
		m_threadPool.push_back(wrkr);
	}
}

void SoundSystem::startBeepingThread() 
{

	while (true) {
		// ready taking inputs
		m_nbAvailableThreads++;
		std::unique_lock<std::mutex> lock(m_mutex);
		m_cv.wait(lock);

		// beep boop
		m_nbAvailableThreads--;
		auto beepData = m_beepsToPlay.front();
		m_beepsToPlay.pop();

		lock.unlock();

		Beep(beepData.first, beepData.second);
	}
}
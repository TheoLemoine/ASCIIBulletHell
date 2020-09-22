#pragma once
#include "ASCIIRenderer.h"
#include "Keyboard.h"
#include "GameClock.h"

// class containing all objects and components to render
class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock, Keyboard* keyboard) {
		m_renderer = renderer;
		m_clock = clock;
		m_keyboard = keyboard;
	}

	void InitWorld() {

	}

	void StartGameLoop() {
	
		float deltaTime;

		while (true)
		{
			deltaTime = m_clock->GetElapsedTimeSinceLastCall();

			m_renderer->Render();
		}

	}

private:
	ASCIIRenderer* m_renderer;
	GameClock* m_clock;
	Keyboard* m_keyboard;


};
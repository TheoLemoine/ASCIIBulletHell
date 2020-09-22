#pragma once
#include "ASCIIRenderer.h"
#include "GameClock.h"

#include <iostream>
#include <string>
#include <sstream>

// class containing all objects and components to render
class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock) {
		m_renderer = renderer;
		m_clock = clock;
	}

	void InitWorld() {

	}

	void StartGameLoop() {
	
		float deltaTime;

		while (true)
		{
			deltaTime = m_clock->GetElapsedTimeSinceLastCall();

			// testing delta time
			std::stringstream converter;

			std::string timestring;
			converter << m_clock->GetElapsedTime();
			converter >> timestring;

			for (std::string::size_type i = 0; i < timestring.size(); i++) {
				m_renderer->SetAt(i, 1, timestring[i], 0x0A);
			}
			
			// shitty code
			std::stringstream converter2;
			std::string deltaTimeString;
			converter2 << deltaTime;
			converter2 >> deltaTimeString;

			for (std::string::size_type i = 0; i < deltaTimeString.size(); i++) {
				m_renderer->SetAt(i, 2, deltaTimeString[i], 0x0A);
			}

			//

			m_renderer->Render();
		}

	}

private:
	ASCIIRenderer* m_renderer;
	GameClock* m_clock;
};
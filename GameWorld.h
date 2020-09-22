#pragma once
#include "ASCIIRenderer.h"
#include "Keyboard.h"
#include "GameClock.h"
#include "PhysicSystem.h"

// class containing all objects and components to render
class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock, Keyboard* keyboard) {
		Renderer = renderer;
		Clock = clock;
		Keyboard = keyboard;
		Physics = new PhysicSystem();
	}

	PhysicSystem* Physics;
	ASCIIRenderer* Renderer;
	GameClock* Clock;
	Keyboard* Keyboard;

	void InitWorld() {
	}

	void StartGameLoop() {

		float deltaTime;

		while (true)
		{
			deltaTime = Clock->GetElapsedTimeSinceLastCall();

			Renderer->Render();
		}

	}

private:

};
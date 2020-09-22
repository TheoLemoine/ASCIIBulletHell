#pragma once
#include "GameWorld.h"
#include "ASCIIRenderer.h"
#include "GameClock.h"
#include "Inputs.h"
#include "PhysicSystem.h"
#include "Starship.h"

// class containing all objects and components to render
GameWorld::GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard) {
	Renderer = renderer;
	Clock = clock;
	Keyboard = keyboard;
	Physics = new PhysicSystem();
}


void GameWorld::InitWorld() {

	Starship player(0, 0);
	Entities.push_back(player);
}

void GameWorld::StartGameLoop() {

	float deltaTime;

	while (true)
	{
		deltaTime = Clock->GetElapsedTimeSinceLastCall();

		Renderer->Render();
	}

}
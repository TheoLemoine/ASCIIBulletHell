//header file
#include "GameWorld.h"
// dependencies
#include "ASCIIRenderer.h"
#include "IEntity.h"
#include "GameClock.h"
#include "Inputs.h"
#include "PhysicSystem.h"
#include "Starship.h"
#include "Constants.h"

// class containing all objects and components to render
GameWorld::GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard) {
	Renderer = renderer;
	Clock = clock;
	Keyboard = keyboard;
	Physics = new PhysicSystem();
}

GameWorld::~GameWorld() {
	// delete all systems
	delete Physics;

	// delete all entities
	for (IEntity* entity : Entities)
	{
		delete entity;
	}
}


void GameWorld::InitWorld() {

	Starship* player = new Starship(GAME_WIDTH / 2, GAME_HEIGHT / 2);
	Entities.push_back(player);

	for (IEntity* entity : Entities)
	{
		entity->Init(this);
	}
}

void GameWorld::StartGameLoop() {

	float deltaTime;

	while (!Keyboard->EchapPress())
	{
		deltaTime = Clock->GetElapsedTimeSinceLastCall();

		Physics->UpdateComponents(deltaTime);

		for (IEntity* entity : Entities) 
		{
			entity->Update(deltaTime);
		}

		Renderer->Render();
	}

}
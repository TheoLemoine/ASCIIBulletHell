//header file
#include "GameWorld.h"
// dependencies
#include "ASCIIRenderer.h"
#include "IEntity.h"
#include "GameClock.h"
#include "Inputs.h"
#include "PhysicSystem.h"
#include "DrawSystem.h"
#include "ColliderSystem.h"
#include "Starship.h"
#include "Ennemy.h"
#include "Constants.h"

// class containing all objects and components to render
GameWorld::GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard) {
	Renderer = renderer;
	Clock = clock;
	Keyboard = keyboard;
	Physics = new PhysicSystem();
	Drawer = new DrawSystem(Renderer);
	Colliders = new ColliderSystem();
}

GameWorld::~GameWorld() {
	// delete all systems
	delete Physics;
	delete Drawer;
	delete Colliders;

	// delete all entities
	for (IEntity* entity : Entities)
	{
		delete entity;
	}
}


void GameWorld::InitWorld() 
{
	Starship* player = new Starship(GAME_WIDTH / 2, GAME_HEIGHT / 2);
	Entities.push_back(player);

	player->Init(this, GAME_WIDTH / 2, GAME_HEIGHT / 2, 0, 0);
}

void GameWorld::StartGameLoop() {

	float deltaTime;

	while (!Keyboard->EchapPress())
	{
		deltaTime = Clock->GetElapsedTimeSinceLastCall();
		Renderer->Clear();

		SpawnEnnemy(deltaTime);

		Physics->UpdateComponents(deltaTime);
		Colliders->UpdateComponents(deltaTime);
		Drawer->UpdateComponents(deltaTime);

		for (size_t i = 0; i < Entities.size(); i++)
		{
			Entities[i]->Update(deltaTime);
		}

		Renderer->Render();
	}

}

IEntity* GameWorld::AddEntity(IEntity* entity)
{
	Entities.push_back(entity);
	return entity;
}

void GameWorld::SpawnEnnemy(float deltaTime)
{
	SpawnEnnemyCooldown -= deltaTime;
	if (SpawnEnnemyCooldown <= 0)
	{
		SpawnEnnemyCooldown = SPAWN_COOLDOWN;
		Ennemy* ennemy = new Ennemy();
		ennemy->Init(this,GAME_WIDTH/2,0,0,1);
		AddEntity(ennemy);
	}
}

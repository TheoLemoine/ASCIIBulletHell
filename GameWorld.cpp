//header file
#include "GameWorld.h"

// entities
#include "Starship.h"
#include "Ennemy.h"
// systems
#include "PhysicSystem.h"
#include "DrawSystem.h"
#include "ColliderSystem.h"
// game utility
#include "Entity.h"
#include "GameClock.h"
#include "Inputs.h"
#include "ASCIIRenderer.h"
#include "Constants.h"


// class containing all objects and components to render
GameWorld::GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard) {
	SpawnEnnemyCooldown = 0;
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
	for (Entity* entity : Entities)
	{
		delete entity;
	}
}


void GameWorld::InitWorld() 
{
	Starship* player = new Starship();
	Entities.push_back(player);

	player->Init(this, GAME_WIDTH / 2, GAME_HEIGHT / 2, 0, 0);
}

void GameWorld::StartGameLoop() {

	float deltaTime;

	while (!Keyboard->EchapPress())
	{
		// prepare
		deltaTime = Clock->GetElapsedTimeSinceLastCall();
		Renderer->Clear();

		SpawnEnnemy(deltaTime);

		// update components
		Physics->UpdateComponents(deltaTime);
		Colliders->UpdateComponents(deltaTime);
		Drawer->UpdateComponents(deltaTime);

		// update entities
		for (size_t i = 0; i < Entities.size(); i++)
		{
			Entities[i]->Update(deltaTime);
		}

		// render
		Renderer->Render();

		// clear all entities that were scheduled to be deleted
		EmptyTrashcan();
	}

}

Entity* GameWorld::AddEntity(Entity* entity)
{
	Entities.push_back(entity);
	return entity;
}

void GameWorld::AddToTrashcan(Entity* entity) 
{
	m_trashcan.push(entity);
}

void GameWorld::EmptyTrashcan() 
{	
	while (!m_trashcan.empty()) 
	{
		Entity* entity = m_trashcan.top();

		auto end_itr = Entities.end();
		for (auto itr = Entities.begin(); itr != end_itr; ++itr)
		{
			if (entity == *itr) 
			{
				Entities.erase(itr); // remove from world
				break;
			}
		}

		entity->Delete(); // ask entity to remove its components
		delete entity; // free memory

		m_trashcan.pop();
	}
}

void GameWorld::SpawnEnnemy(float deltaTime)
{
	SpawnEnnemyCooldown -= deltaTime;
	if (SpawnEnnemyCooldown <= 0)
	{
		SpawnEnnemyCooldown = SPAWN_COOLDOWN;
		Ennemy* ennemy = new Ennemy();
		ennemy->Init(this, GAME_WIDTH / 2, 0, 0, 1);
		AddEntity(ennemy);
	}
}



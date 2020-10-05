//header file
#include "GameWorld.h"

// entities
#include "Starship.h"
#include "EnnemySpawner.h"
// systems
#include "PhysicSystem.h"
#include "DrawSystem.h"
#include "ColliderSystem.h"
// game utility
#include "Entity.h"
#include "GameClock.h"
#include "Inputs.h"
#include "Score.h"
#include "ASCIIRenderer.h"
#include "Constants.h"


// class containing all objects and components to render
GameWorld::GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard, Score* scoreBoard) {
	Renderer = renderer;
	Clock = clock;
	Keyboard = keyboard;
	ScoreBoard = scoreBoard;
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
	AddEntity(player);
	player->Init(this, GAME_WIDTH / 2, GAME_HEIGHT / 2, 0, 0);

	EnnemySpawner* spawner = new EnnemySpawner(ENMY_SPAWN_COOLDOWN);
	AddEntity(spawner);
	spawner->Init(this, 0, 0, 0, 0);
}

void GameWorld::StartGameLoop() {

	float deltaTime;

	while (!Keyboard->EchapPress())
	{
		// prepare
		deltaTime = Clock->GetElapsedTimeSinceLastCall();
		Renderer->Clear();

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
		ScoreBoard->DrawScore();
		Renderer->Render(deltaTime);

		// clear all entities that were scheduled to be deleted
		EmptyTrashcan();

		if (Keyboard->ResetPress())
			Reset();
	}

}

void GameWorld::Reset()
{
	// delete all entities
	for (Entity* entity : Entities)
	{
		entity->Delete();
		delete entity;
	}
	ScoreBoard->Reset();
	Entities.clear();
	InitWorld();
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
				entity->Delete(); // ask entity to remove its components
				delete entity; // free memory
				break;
			}
		}

		m_trashcan.pop();
	}
}

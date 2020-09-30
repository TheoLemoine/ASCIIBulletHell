// header file
#include "EnnemySpawner.h"

#include "GameWorld.h"
#include "Ennemy.h"
#include "Constants.h"


void EnnemySpawner::Init(GameWorld* world, double startX, double startY, double velX, double velY) 
{
	m_world = world;
}

void EnnemySpawner::Update(float deltaTime)
{
	if (m_currentSpawnCoolDown < 0.f) 
	{
		m_currentSpawnCoolDown = m_spawnCoolDown;
	
		Ennemy* ennemy = new Ennemy();
		ennemy->Init(m_world, rand() % GAME_WIDTH, rand() % 4, randFloat(-2.f, 2.f), randFloat(-0.5f, 2.f));
		m_world->AddEntity(ennemy);
	}
	else 
	{
		m_currentSpawnCoolDown -= deltaTime;
	}
}

void EnnemySpawner::Delete() { }

EnnemySpawner::EnnemySpawner(float coolDown)
{
	m_world = nullptr;

	m_currentSpawnCoolDown = 0.f;
	m_spawnCoolDown = coolDown;
}

EnnemySpawner::~EnnemySpawner() { }

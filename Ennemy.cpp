// header file
#include "Ennemy.h"

// components and systems
#include "PhysicSystem.h"
#include "PhysicComponent.h"
#include "ColliderSystem.h"
#include "ColliderComponent.h"
#include "DrawSystem.h"
#include "DrawComponent.h"

// game utility
#include "GameWorld.h"
#include "Constants.h"


void Ennemy::Init(GameWorld* world, double startX, double startY, double velX, double velY)
{
	m_world = world;

	m_physic = m_world->Physics->RequestComponent(startX, startY, velX, velY);

	m_collider = m_world->Colliders->RequestComponent(m_physic, 1, Tag::ENNEMY);
	// bind collision event
	m_collider->AddCollisionListener(std::bind(&Ennemy::HandleCollision, this, std::placeholders::_1));

	m_draw = m_world->Drawer->RequestComponent(m_physic,
		// sprites
		{
			{
				' ', '_', '_', ' ',
				'/', '.', '.','\\',
				'\\','_', '_', '/',
				' ', '"', '"', ' '
			},
			{
				' ', '_', '_', ' ',
				'/', '.', '.','\\',
				'\\','_', '_', '/',
				' ', 'W', 'W', ' '
			},
			{
				' ', '_', '_', ' ',
				'/', '.', '.','\\',
				'\\','_', '_', '/',
				' ', 'w', 'w', ' '
			}
		},
		// colors
		{
			{
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED
			},
			{
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED
			},
			{
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED,
				B_RED, B_RED, B_RED, B_RED
			}
		},
		4, 4, 1.5);
}

void Ennemy::HandleCollision(ColliderComponent* other)
{
	m_world->AddToTrashcan(this);
}

void Ennemy::Update(float deltaTime) { }

void Ennemy::Delete() {
	// ask systems to delete linked components
	m_world->Physics->DeleteComponent(m_physic);
	m_world->Drawer->DeleteComponent(m_draw);
	m_world->Colliders->DeleteComponent(m_collider);
}

Ennemy::Ennemy()
{ 
	m_world = nullptr;
	m_collider = nullptr;
	m_draw = nullptr;
	m_physic = nullptr;
}

Ennemy::~Ennemy() { }

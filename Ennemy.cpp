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
	m_physic = world->Physics->RequestComponent(startX, startY, velX, velY);
	m_collider = world->Colliders->RequestComponent(m_physic, 1, Tag::PROJECTILE);
	m_draw = world->Drawer->RequestComponent(m_physic,
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

void Ennemy::Update(float deltaTime)
{
}

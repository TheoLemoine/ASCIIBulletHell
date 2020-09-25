#include "PhysicSystem.h"
#include "ColliderSystem.h"
#include "DrawSystem.h"
#include "PhysicComponent.h"
#include "ColliderComponent.h"
#include "DrawComponent.h"
#include "GameWorld.h"
#include "Constants.h"
#include "Ennemy.h"

void Ennemy::Init(GameWorld* world, float startX, float startY, float velX, float velY)
{
	m_physic = world->Physics->RequestComponent(startX, startY, velX, velY);
	m_collider = world->Colliders->RequestComponent(this, m_physic, 1, Tag::PROJECTILE);
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

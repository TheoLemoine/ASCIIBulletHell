#include "GameWorld.h"
#include "PhysicSystem.h"
#include "ColliderSystem.h"
#include "DrawSystem.h"
#include "PhysicComponent.h"
#include "ColliderComponent.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include <Windows.h>

#include "Bullet.h"

constexpr int A_BLCK = 0x00;
constexpr int D_BLUE = FOREGROUND_BLUE;
constexpr int B_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

void Bullet::Init(GameWorld* world, float startX, float startY, float velX, float velY)
{
	m_physic = world->Physics->RequestComponent(startX, startY, velX, velY);
	m_collider = world->Colliders->RequestComponent(this, m_physic, 1, ColliderComponent::Tag::PROJECTILE);
	m_draw = world->Drawer->RequestComponent(m_physic,
		// sprites
		{
			{
				' ', '^', ' ',
				'/', '|','\\',
				' ', '|', ' ',
			},
			{
				' ', '^', ' ',
			   '\'', '|','\'',
				' ','\'', ' ',
			},
		},
		// colors
		{
			{
				A_BLCK, B_BLUE, A_BLCK,
				B_BLUE, B_BLUE, B_BLUE,
				A_BLCK, B_BLUE, A_BLCK,
			},
			{
				A_BLCK, B_BLUE, A_BLCK,
				D_BLUE, B_BLUE, D_BLUE,
				A_BLCK, D_BLUE, A_BLCK,
			},
		},
	3, 3, 1.5);
}

void Bullet::Update(float deltaTime)
{
}

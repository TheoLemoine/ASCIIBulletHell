// header file
#include "Bullet.h"

// other entities
#include "Particles.h"

// components and systems
#include "ColliderSystem.h"
#include "ColliderComponent.h"
#include "DrawSystem.h"
#include "DrawComponent.h"
#include "PhysicSystem.h"
#include "PhysicComponent.h"
#include "SoundSystem.h"
// game utility
#include "GameWorld.h"
#include "Entity.h"
#include "Constants.h"
// external deps
#include <Windows.h>
#include <functional>


void Bullet::Init(GameWorld* world, double startX, double startY, double velX, double velY)
{
	m_world = world;

	m_physic = m_world->Physics->RequestComponent(startX, startY, velX, velY);

	m_collider = m_world->Colliders->RequestComponent(m_physic, 1, Tag::NEW_PROJECTILE);
	// bind collision event
	m_collider->AddCollisionListener(std::bind(&Bullet::HandleCollision, this, std::placeholders::_1));

	m_draw = m_world->Drawer->RequestComponent(m_physic,
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
				A_BLCK, B_YLOW, A_BLCK,
				B_BLUE, B_YLOW, B_BLUE,
				A_BLCK, B_BLUE, A_BLCK,
			},
			{
				A_BLCK, B_YLOW, A_BLCK,
				D_BLUE, D_YLOW, D_BLUE,
				A_BLCK, B_BLUE, A_BLCK,
			},
		},
	3, 3, 4);
}

void Bullet::HandleCollision(ColliderComponent* other)
{
	m_world->AddToTrashcan(this);
	m_world->Sound->AsyncBeep(420, 200);

	Particles* particleSystem = new Particles({ '+', '*', '.', '#' }, B_BLUE, 30, 2, 8.f, m_physic->Velocity);
	particleSystem->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
	m_world->AddEntity(particleSystem);
}

void Bullet::Update(float deltaTime)
{
	m_timeAlive += deltaTime;

	if (m_timeAlive > BLT_TIME_BEFORE_TAG_SWAP) {
		m_collider->ComponentTag = Tag::PROJECTILE;
	}
}

void Bullet::Delete() {
	// ask systems to delete linked components
	m_world->Physics->DeleteComponent(m_physic);
	m_world->Drawer->DeleteComponent(m_draw);
	m_world->Colliders->DeleteComponent(m_collider);
}

Bullet::Bullet() {
	// set on Init()
	m_world = nullptr;
	m_physic = nullptr;
	m_collider = nullptr;
	m_draw = nullptr;

	m_timeAlive = 0.f;
}

Bullet::~Bullet() { }
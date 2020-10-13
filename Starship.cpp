// header file
#include "Starship.h"
// other entities
#include "Bullet.h"
#include "Particles.h"
// components and systems
#include "ColliderSystem.h"
#include "ColliderComponent.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
// game utility
#include "GameWorld.h"
#include "Inputs.h"
#include "Entity.h"
#include "Constants.h"
// external deps
#include <Windows.h>
#include <functional>
#include <iostream>


void Starship::Init(GameWorld* world, double startX, double startY, double velX, double velY) {
	m_world = world;

	m_physic = m_world->Physics->RequestComponent(startX, startY, 0, 0);

	m_collider = m_world->Colliders->RequestComponent(m_physic, 2, Tag::SPACESHIP);
	// bind collision event
	m_collider->AddCollisionListener(std::bind(&Starship::HandleCollision, this, std::placeholders::_1));

	m_draw = m_world->Drawer->RequestComponent(m_physic,
		// animation sprites
		{ 
			{
				' ', ' ', '^', ' ', ' ',
				' ', '/', 'H','\\', ' ',
				'/', 'd', 'W', 'b','\\',
				' ', '"', ' ', '"', ' ',
			},
			{
				' ', ' ', '^', ' ', ' ',
				' ', '/', 'H','\\', ' ',
				'/', 'd', 'W', 'b','\\',
				' ', 'W', ' ', 'W', ' ',
			},
			{
				' ', ' ', '^', ' ', ' ',
				' ', '/', 'H','\\', ' ',
				'/', 'd', 'W', 'b','\\',
				' ', 'w', ' ', 'w', ' ',
			}
		}, 
		// animation colors
		{ 
			{
				A_BLCK, A_BLCK, D_CYAN, A_BLCK, A_BLCK,
				A_BLCK, D_CYAN, B_CYAN, D_CYAN, A_BLCK,
				D_CYAN, B_CYAN, B_CYAN, B_CYAN, D_CYAN,
				A_BLCK, D_PRPL, A_BLCK, D_PRPL, A_BLCK,
			},
			{
				A_BLCK, A_BLCK, D_CYAN, A_BLCK, A_BLCK,
				A_BLCK, D_CYAN, B_CYAN, D_CYAN, A_BLCK,
				D_CYAN, B_CYAN, B_CYAN, B_CYAN, D_CYAN,
				A_BLCK, B_PRPL, A_BLCK, B_PRPL, A_BLCK,
			},
			{
				A_BLCK, A_BLCK, D_CYAN, A_BLCK, A_BLCK,
				A_BLCK, D_CYAN, B_CYAN, D_CYAN, A_BLCK,
				D_CYAN, B_CYAN, B_CYAN, B_CYAN, D_CYAN,
				A_BLCK, B_PRPL, A_BLCK, B_PRPL, A_BLCK,
			}
		},
	5, 4, 2);

	m_keyboard = m_world->Keyboard;
}

void Starship::Update(float deltaTime) {
	m_physic->Acceleration.y = 0;
	m_physic->Acceleration.x = 0;

	if (m_physic->Velocity.Dist(Vec2(0, 0)) <= SS_IMMOBILITY)
		m_physic->Velocity = Vec2(0, 0);

	float downed = m_keyboard->DownPress();
	float uped = m_keyboard->UpPress();
	float righted = m_keyboard->RightPress();
	float lefted = m_keyboard->LeftPress();

	if(downed != 0 || lefted != 0 || righted != 0 || uped != 0)
	std::cout << "down : " << downed << std::endl << "up : " << uped << std::endl << "right : " << righted << std::endl << "left : " << lefted << std::endl;



	//Accelerate up and down
	if (downed != 0 || (m_physic->Velocity.y < 0 && !uped))
		m_physic->Acceleration.y = SS_ACCELERATION_POWER * downed;
	if (uped != 0 || (m_physic->Velocity.y > 0 && !downed))
		m_physic->Acceleration.y = -SS_ACCELERATION_POWER * uped;

	//Accelerate right and left
	if (lefted != 0 || (m_physic->Velocity.x > 0 && !righted))
		m_physic->Acceleration.x = -SS_ACCELERATION_POWER * lefted;
	if (righted != 0 || (m_physic->Velocity.x < 0 && !lefted))
		m_physic->Acceleration.x = SS_ACCELERATION_POWER * righted;
	

	m_lastShoot -= deltaTime;
	//Shoot
	if (m_keyboard->SpacePress() && m_lastShoot <=0)
	{
		Shoot();
		m_lastShoot = SS_COOLDOWN;
	}
}

void Starship::Delete() {

	// ask systems to delete linked components
	m_world->Physics->DeleteComponent(m_physic);
	m_world->Drawer->DeleteComponent(m_draw);
	m_world->Colliders->DeleteComponent(m_collider);
}

void Starship::Shoot()
{
	//TODO INVOKE BULLET
	Vec2 bulletPos = m_physic->Position + SS_SHOOT_POS;
	float spread = randFloat(-SS_SPREAD_RATIO, SS_SPREAD_RATIO);
	Vec2 bulletSpeed = Vec2(
		m_physic->Velocity.x / SS_BULLET_RATIO_SPEED + spread,
		m_physic->Velocity.y / SS_BULLET_RATIO_SPEED + BLT_SPEED
	);

	Bullet* bullet = new Bullet();
	bullet->Init(m_world, bulletPos.x, bulletPos.y, bulletSpeed.x, bulletSpeed.y);
	m_world->AddEntity(bullet);

}

void Starship::HandleCollision(ColliderComponent* other) 
{

	m_hp--;

	if (m_hp <= 0) 
	{

		m_world->AddToTrashcan(this);

		// and handle dying
		Particles* particleSystemOut = new Particles({ '.', '*', '0', 'o' }, B_CYAN, 30, 2, 15.f, m_physic->Velocity);
		particleSystemOut->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
		m_world->AddEntity(particleSystemOut);

		Particles* particleSystemCenter = new Particles({ '#', '@', '&' }, B_PRPL, 10, 0.5, 30.f, m_physic->Velocity);
		particleSystemCenter->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
		m_world->AddEntity(particleSystemCenter);
	}
	else
	{
		// and handle dying
		Particles* particleSystemOut = new Particles({ '@', '#', '*', '0', 'o' }, B_CYAN, 5, 1.2, 5.f, m_physic->Velocity);
		particleSystemOut->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
		m_world->AddEntity(particleSystemOut);
	}
	
}

Starship::Starship() {
	// set on Init()
	m_world = nullptr;
	m_physic = nullptr;
	m_collider = nullptr;
	m_keyboard = nullptr;
	m_draw = nullptr;

	m_lastShoot = 0.f;
	m_hp = SS_HP;
}

Starship::~Starship() { }
// header file
#include "Starship.h"
// dependencies
#include "IEntity.h"
#include "ASCIIRenderer.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "ColliderSystem.h"
#include "ColliderComponent.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include "ColliderComponent.h"
#include "ColliderSystem.h"
#include "Inputs.h"
#include "GameWorld.h"
#include "Constants.h"
#include "Bullet.h"

//temp
#include <iostream>

constexpr int A_BLCK = 0x00; // all black
constexpr int B_CYAN = 0x0B; // bright cyan
constexpr int D_CYAN = 0x03; // dark cyan
constexpr int B_PRPL = 0x0D; // bright purple
constexpr int D_PRPL = 0x05; // dark purple

void Starship::Init(GameWorld* world, float startX, float startY, float velX, float velY) {
	m_world = world;
	m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);

	m_collider = world->Colliders->RequestComponent(this,m_physic,SS_SIZE,Tag::SPACESHIP);
	m_draw = world->Drawer->RequestComponent(m_physic, 
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

	m_collider = world->Colliders->RequestComponent(this, m_physic, 2, Tag::SPACESHIP);
	// bind collision event
	__hook(&ColliderComponent::OnCollision, m_collider, &Starship::HandleCollision);

	m_keyboard = world->Keyboard;
}

void Starship::Update(float deltaTime) {
	m_physic->Acceleration.y = 0;
	m_physic->Acceleration.x = 0;

	if (m_physic->Velocity.Dist(Vec2(0, 0)) <= SS_IMMOBILITY)
		m_physic->Velocity = Vec2(0, 0);

	bool downed = m_keyboard->DownPress();
	bool uped = m_keyboard->UpPress();
	bool righted = m_keyboard->RightPress();
	bool lefted = m_keyboard->LeftPress();

	//Accelerate up and down
	if (downed || (m_physic->Velocity.y < 0 && !uped))
		m_physic->Acceleration.y = SS_ACCELERATION_POWER;
	if (uped || (m_physic->Velocity.y > 0 && !downed))
		m_physic->Acceleration.y = -SS_ACCELERATION_POWER;

	//Accelerate right and left
	if (lefted || (m_physic->Velocity.x > 0 && !righted))
		m_physic->Acceleration.x = -SS_ACCELERATION_POWER;
	if (righted || (m_physic->Velocity.x < 0 && !lefted))
		m_physic->Acceleration.x = SS_ACCELERATION_POWER;
	

	m_lastShoot -= deltaTime;
	//Shoot
	if (m_keyboard->SpacePress() && m_lastShoot <=0)
	{
		Shoot();
		m_lastShoot = SS_COOLDOWN;
	}
}

void Starship::Shoot()
{
	//TODO INVOKE BULLET
	Bullet* bullet = new Bullet();
	Vec2 bulletPos = m_physic->Position + SS_SHOOT_POS;
	Vec2 bulletSpeed = Vec2(m_physic->Velocity.x/SS_BULLET_RATIO_SPEED,BULLET_SPEED+m_physic->Velocity.y/SS_BULLET_RATIO_SPEED);
	bullet->Init(m_world, bulletPos.x, bulletPos.y, bulletSpeed.x, bulletSpeed.y);
	m_world->AddEntity(bullet);

}

void Starship::HandleCollision(ColliderComponent* other) 
{
	// check for tag, and handle dying
}

Starship::Starship(float x, float y) {
	startX = x;
	startY = y;

	// set on Init()
	m_physic = nullptr;
	m_keyboard = nullptr;
	m_draw = nullptr;
}

Starship::~Starship() {
	delete m_physic;
	delete m_draw;
	delete m_collider;

	__unhook(&ColliderComponent::OnCollision, m_collider, &Starship::HandleCollision);
}
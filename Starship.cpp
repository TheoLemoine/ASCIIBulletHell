// header file
#include "Starship.h"
// dependencies
#include "IEntity.h"
#include "ASCIIRenderer.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include "ColliderComponent.h"
#include "ColliderSystem.h"
#include "Inputs.h"
#include "GameWorld.h"
#include "Constants.h"

//temp
#include <iostream>

constexpr int A_BLCK = 0x00; // all black
constexpr int B_CYAN = 0x0B; // bright cyan
constexpr int D_CYAN = 0x03; // dark cyan
constexpr int B_PRPL = 0x0D; // bright purple
constexpr int D_PRPL = 0x05; // dark purple

void Starship::Init(GameWorld* world) {
	m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);

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

	m_collider = world->Collider->RequestComponent(this, m_physic, 2, Tag::SPACESHIP);
	// bind collision event
	__hook(&ColliderComponent::OnCollision, m_collider, &Starship::HandleCollision);

	m_keyboard = world->Keyboard;
}

void Starship::Update(float deltaTime) {
	m_physic->Acceleration.y = 0;
	m_physic->Acceleration.x = 0;

	bool downed = m_keyboard->DownPress();
	bool uped = m_keyboard->UpPress();
	bool righted = m_keyboard->RightPress();
	bool lefted = m_keyboard->LeftPress();

	//Accelerate up and down
	if (downed || (m_physic->Velocity.y < 0 && !uped))
		m_physic->Acceleration.y = ACCELERATION_POWER;
	if (uped || (m_physic->Velocity.y > 0 && !downed))
		m_physic->Acceleration.y = -ACCELERATION_POWER;

	//Accelerate right and left
	if (lefted || (m_physic->Velocity.x > 0 && !righted))
		m_physic->Acceleration.x = -ACCELERATION_POWER;
	if (righted || (m_physic->Velocity.x < 0 && !lefted))
		m_physic->Acceleration.x = ACCELERATION_POWER;

	//Shoot
	if (m_keyboard->SpacePress())
	{
		Shoot();
	}
}

void Starship::Shoot()
{
	//TODO INVOKE BULLET
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
// header file
#include "Starship.h"
// dependencies
#include "IEntity.h"
#include "ASCIIRenderer.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include "Inputs.h"
#include "GameWorld.h"
#include "Constants.h"

//temp
#include <iostream>

void Starship::Init(GameWorld* world) {
	m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);
	m_draw = world->Drawer->RequestComponent(m_physic, 'V');
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
}
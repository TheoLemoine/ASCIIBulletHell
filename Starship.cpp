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

	//Accelerate up and down
	if (m_keyboard->DownPress())
		m_physic->Acceleration.y = 1;
	else if (m_keyboard->UpPress())
		m_physic->Acceleration.y = -1;
	else
		//Deceleration when not press key
		m_physic->Acceleration.y = m_physic->Velocity.y * -1;

	//Accelerate right and left
	if (m_keyboard->LeftPress())
		m_physic->Acceleration.x = -1;
	else if (m_keyboard->RightPress())
		m_physic->Acceleration.x = 1;
	else
		//Deceleration when not press key
		m_physic->Acceleration.x = m_physic->Velocity.x * -1;

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
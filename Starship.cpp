// header file
#include "Starship.h"
// dependencies
#include "IEntity.h"
#include "ASCIIRenderer.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "Inputs.h"
#include "GameWorld.h"

//temp
#include <iostream>

void Starship::Init(GameWorld* world) {
	m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);
	m_keyboard = world->Keyboard;
	m_renderer = world->Renderer;
}

void Starship::Update(float deltaTime) {
	m_physic->Acceleration.y = 0;
	m_physic->Acceleration.x = 0;

	if (m_keyboard->DownPress())
		m_physic->Acceleration.y = -1;
	if (m_keyboard->UpPress())
		m_physic->Acceleration.y = 1;
	if (m_keyboard->LeftPress())
		m_physic->Acceleration.x = -1;
	if (m_keyboard->RightPress())
		m_physic->Acceleration.x = 1;

	//TODO REMOVE RENDERER EACH FRAME
	//TODO MOVE TO RENDERER WHILE
	m_renderer->SetAt(
		m_physic->Position.x,
		m_physic->Position.y,
		'V',
		0x0E
	);
}

Starship::Starship(float x, float y) {
	startX = x;
	startY = y;

	// set on Init()
	m_physic = nullptr;
	m_keyboard = nullptr;
	m_renderer = nullptr;
}

Starship::~Starship() {
	delete m_physic;
}
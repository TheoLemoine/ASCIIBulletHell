#include "PhysicSystem.h"
#include "Keyboard.h"
#include "IEntity.h"

class Starship : IEntity
{
public:
	void Init(GameWorld* world) {
		m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);
		m_keyboard = world->Keyboard;
	}

	void Update(float deltaTime) {
		if (m_keyboard->DownPress())
			m_physic->Acceleration.y = -1;
		if (m_keyboard->UpPress())
			m_physic->Acceleration.y = 1;
		if (m_keyboard->LeftPress())
			m_physic->Acceleration.x = -1;
		if (m_keyboard->RightPress())
			m_physic->Acceleration.x = 1;
	}

	Starship(float x, float y) {
		startX = x;
		startY = y;
	}

	~Starship() {
		delete m_physic;
	}

private:
	PhysicComponent* m_physic;
	Keyboard* m_keyboard;

	float startX, startY;
};
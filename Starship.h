#include "Physic.h"
#include "Keyboard.h"
#include "IEntity.h"

class Starship: IEntity
{
public:
	void Update(ASCIIRenderer* renderer, Keyboard* keyboard, float deltaTime) {

		if (keyboard->DownPress())
			m_physic->ySpeed = -1;
		if (keyboard->UpPress())
			m_physic->ySpeed = 1;
		if (keyboard->LeftPress())
			m_physic->xSpeed = -1;
		if (keyboard->RightPress())
			m_physic->xSpeed = 1;

	}

	Starship() {
		m_physic = new Physic(0,0);
	}

	~Starship() {
		delete m_physic;
	}

private:
	Physic* m_physic;
};
#include "Physic.h"
#include "Keyboard.h"
#include "IEntity.h"

class Starship: IEntity
{
public:
	void Update(ASCIIRenderer* renderer, Keyboard* keyboard, float deltaTime) {

	void Update(Keyboard* keys,float deltaTime)
	{
		if (keys->DownPress())
			physic->Speed.y = -1;
		if (keys->UpPress())
			physic->Speed.y = 1;
		if (keys->LeftPress())
			physic->Speed.x = -1;
		if (keys->RightPress())
			physic->Speed.x = 1;
	}

	Starship() { Starship(0, 0);}

	Starship(float x, float y)
	{
		physic = new Physic(x, y);
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
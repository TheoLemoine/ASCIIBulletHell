#include "Physic.h"
#include "Keyboard.h"
class Starship
{
public:
	Physic* physic;
	//TODO add renderer

	void Update(Keyboard* keys,float deltaTime)
	{
		if (keys->DownPress())
			physic->ySpeed = -1;
		if (keys->UpPress())
			physic->ySpeed = 1;
		if (keys->LeftPress())
			physic->xSpeed = -1;
		if (keys->RightPress())
			physic->xSpeed = 1;
	}

	Starship() {
		physic = new Physic(0,0);
	}
};
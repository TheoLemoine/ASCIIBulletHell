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

	~Starship()
	{
		delete physic;
	}
};
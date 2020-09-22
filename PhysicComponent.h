#include "Vec2.h"

struct PhysicComponent
{
public:
	Vec2 Position;
	Vec2 Velocity;
	Vec2 Acceleration;
	//TODO COLLIDER with Circle and distance

	PhysicComponent(float posX, float posY, float velX, float velY)
	{
		Position = Vec2(posX, posY);
		Velocity = Vec2(velX, velY);
		Acceleration = Vec2(0, 0);
	}
};

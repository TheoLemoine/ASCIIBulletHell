#pragma once
#include "Vec2.h"


struct PhysicComponent
{
public:
	Vec2 Position;
	Vec2 Velocity;
	Vec2 Acceleration;

	PhysicComponent(double posX, double posY, double velX, double velY);

	double Dist(PhysicComponent* physic);
};

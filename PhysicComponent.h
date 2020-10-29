#pragma once
#include "Vec2.h"


struct PhysicComponent
{
public:
	Vec2<double> Position;
	Vec2<double> Velocity;
	Vec2<double> Acceleration;

	PhysicComponent(double posX, double posY, double velX, double velY);

	double Dist(PhysicComponent* physic);
};

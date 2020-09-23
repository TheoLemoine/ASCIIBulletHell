#pragma once
#include "Vec2.h"

// struct definition
struct PhysicComponent
{
public:
	Vec2 Position;
	Vec2 Velocity;
	Vec2 Acceleration;
	//TODO COLLIDER with Circle and distance

	PhysicComponent(float posX, float posY, float velX, float velY);
};

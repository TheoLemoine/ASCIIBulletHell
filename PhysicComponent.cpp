#include "PhysicComponent.h"
#include "Vec2.h"

PhysicComponent::PhysicComponent(float posX, float posY, float velX, float velY)
{
	Position = Vec2(posX, posY);
	Velocity = Vec2(velX, velY);
	Acceleration = Vec2(0, 0);
}

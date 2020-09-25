// header file
#include "PhysicComponent.h"

#include "Vec2.h"


PhysicComponent::PhysicComponent(double posX, double posY, double velX, double velY)
{
	Position = Vec2(posX, posY);
	Velocity = Vec2(velX, velY);
	Acceleration = Vec2(0, 0);
}


double PhysicComponent::Dist(PhysicComponent* physic)
{
	return Position.Dist(physic->Position);
}

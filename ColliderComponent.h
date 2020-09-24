#pragma once
#include "Constants.h"

//Forward declaration
struct PhysicComponent;
class IEntity;

class ColliderComponent
{
public:
	PhysicComponent* Physic;
	IEntity* Entity;
	float Size;
	Tag ComponentTag;
	ColliderComponent(IEntity* gameobject, PhysicComponent* physics, float size, Tag tag);
	__event void OnCollision(ColliderComponent* other);
};


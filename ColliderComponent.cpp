// header file
#include "ColliderComponent.h"

#include "PhysicComponent.h"
#include "Constants.h"


ColliderComponent::ColliderComponent(PhysicComponent* physics, double size, Tag tag)
{
	Physic = physics;
	Size = size;
	ComponentTag = tag;
}
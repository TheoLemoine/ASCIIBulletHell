#include "IEntity.h"
#include "PhysicComponent.h"
#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(IEntity* gameobject, PhysicComponent* physics, float size, Tag tag)
{
	Entity = gameobject;
	Physic = physics;
	Size = size;
	ComponentTag = tag;
}
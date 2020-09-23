#include "ColliderComponent.h"
#include "ColliderSystem.h"

ColliderComponent* ColliderSystem::RequestComponent(IEntity* gameobject, PhysicComponent* physics, float size, ColliderComponent::Tag tag)
{
	ColliderComponent* newComponent = new ColliderComponent(gameobject,physics,size,tag);

	Components.push_back(newComponent);
	return newComponent;
}

void ColliderSystem::UpdateComponents(float deltaTime)
{

	for (ColliderComponent* component : Components)
	{
		for (ColliderComponent* collider : Components)
		{
			if (component->Collide(collider))
				component->Collision(collider->myTag);
		}
	}

}
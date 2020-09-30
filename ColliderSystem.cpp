// header file
#include "ColliderSystem.h"

#include "ColliderComponent.h"
#include "PhysicComponent.h"
#include "Constants.h"


ColliderComponent* ColliderSystem::RequestComponent(PhysicComponent* physics, double size, Tag tag)
{
	ColliderComponent* newComponent = new ColliderComponent(physics, size, tag);

	Components.push_back(newComponent);
	return newComponent;
}

void ColliderSystem::DeleteComponent(ColliderComponent* colliderPointer) 
{
	auto end_itr = Components.end();
	for (auto itr = Components.begin(); itr != end_itr; ++itr)
	{
		if (*itr == colliderPointer) {
			itr = Components.erase(itr);
			break;
		}
	}

	delete colliderPointer;
}

void ColliderSystem::UpdateComponents(float deltaTime)
{
	int length = Components.size();

	// checking each element against each other without duplicate
	for (int i = 0; i < length; i++)
	{
		auto& first = Components[i];

		// all items up to i have already been chacked against every other, we can skip them
		for (int j = i+1; j < length; j++)
		{
			auto& second = Components[j];

			// checking if tag1 collides with tag2
			if (!COLLISION_MATRIX[(int)first->ComponentTag][(int)second->ComponentTag]) continue;

			if (first->Physic->Dist(second->Physic) <= (first->Size) + (second->Size)) {
				first->TriggerCollision(second);
				second->TriggerCollision(first);
			}
		}
	}
}
// header file
#include "ColliderComponent.h"

#include "Entity.h"
#include "PhysicComponent.h"
#include "Constants.h"
#include <utility>


ColliderComponent::ColliderComponent(PhysicComponent* physics, double size, Tag tag)
{
	Physic = physics;
	Size = size;
	ComponentTag = tag;
}

void ColliderComponent::AddCollisionListener(CollisionCallback callback) 
{
	m_callbacks.push_back(callback);
}

void ColliderComponent::TriggerCollision(ColliderComponent* other) 
{
	auto end_itr = m_callbacks.end();
	for (auto itr = m_callbacks.begin(); itr != end_itr; ++itr)
	{
		(*itr)(other);
	}
}
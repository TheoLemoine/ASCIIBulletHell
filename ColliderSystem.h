#pragma once
#include <vector>


class ColliderSystem
{
private:
	std::vector<ColliderComponent*> Components;
public:
	ColliderComponent* RequestComponent(IEntity* gameobject, PhysicComponent* physics, float size, ColliderComponent::Tag tag);
	void UpdateComponents(float deltaTime)
};
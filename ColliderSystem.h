#pragma once
#include <vector>
#include "Constants.h"

struct ColliderComponent;

class ColliderSystem
{
private:
	std::vector<ColliderComponent*> Components;
public:
	ColliderComponent* RequestComponent(IEntity* gameobject, PhysicComponent* physics, float size, Tag tag);
	void UpdateComponents(float deltaTime);
};
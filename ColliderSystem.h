#pragma once
#include "Constants.h"
#include <vector>

struct ColliderComponent;
struct PhysicComponent;


class ColliderSystem
{
private:
	std::vector<ColliderComponent*> Components;
public:
	ColliderComponent* RequestComponent(PhysicComponent* physics, double size, Tag tag);
	void DeleteComponent(ColliderComponent* componentPointer);
	void UpdateComponents(float deltaTime);
};
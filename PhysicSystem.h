#pragma once
#include <vector>

struct PhysicComponent;


class PhysicSystem
{

public:
	std::vector<PhysicComponent*> Components;

	PhysicComponent* RequestComponent(double posX, double posY, double velX, double velY);
	void DeleteComponent(PhysicComponent* componentPointer);
	void UpdateComponents(float deltaTime);
};
#pragma once
#include <vector>


// forward declaration
class PhysicComponent;

// class definition
class PhysicSystem
{

public:
	std::vector<PhysicComponent> Components;

	PhysicComponent* RequestComponent(float posX, float posY, float velX, float velY);
	void UpdateComponents(float deltaTime);

};
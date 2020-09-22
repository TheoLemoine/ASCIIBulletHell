#pragma once
#include <vector>
#include <math.h>
#include "Constants.h"
#include "PhysicComponent.h"


class PhysicSystem
{

public:
	std::vector<PhysicComponent> Components;

	PhysicComponent* RequestComponent(float posX, float posY, float velX, float velY);

	void UpdateComponents(float deltaTime);

};
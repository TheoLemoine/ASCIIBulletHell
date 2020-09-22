#pragma once
#include <vector>
#include <math.h>
#include "Constants.h"
#include "PhysicComponent.h"


class PhysicSystem
{

public:
	std::vector<PhysicComponent> Components;

	PhysicComponent* RequestComponent(float posX, float posY, float velX, float velY)
	{
		PhysicComponent newComponent(posX, posY, velX, velY);

		Components.push_back(newComponent);

		return &newComponent;
	}

	void UpdateComponents(float deltaTime)
	{

		for (auto component : Components)
		{
			component.Velocity += component.Acceleration * deltaTime;

			component.Velocity.Clamp(-MAX_VELOCITY, MAX_VELOCITY);

			component.Position += component.Velocity * deltaTime;

			// check for bounces on left and right
			if ((component.Position.x > GAME_WIDTH && component.Velocity.x > 0)
				|| (component.Position.x < 0 && component.Velocity.x < 0)) {
				component.Velocity = component.Velocity * -1;
			}

			// tp from top to bottom and bottom to top
			if (component.Position.y > GAME_HEIGHT || component.Position.y < 0) {
				component.Position.y = fmod(component.Position.y + GAME_HEIGHT, GAME_HEIGHT);
			}
		}

	}

};
// header file
#include "PhysicSystem.h"

#include "PhysicComponent.h"
#include "Constants.h"
#include <math.h>



PhysicComponent* PhysicSystem::RequestComponent(double posX, double posY, double velX, double velY)
{
	PhysicComponent* newComponent = new PhysicComponent(posX, posY, velX, velY);

	Components.push_back(newComponent);
	return newComponent;
}

void PhysicSystem::DeleteComponent(PhysicComponent* physicPointer)
{
	auto end_itr = Components.end();
	for (auto itr = Components.begin(); itr != end_itr; ++itr)
	{
		if (*itr == physicPointer) {
			Components.erase(itr);
			break;
		}
	}

	delete physicPointer;
}

void PhysicSystem::UpdateComponents(float deltaTime)
{

	for (PhysicComponent* component : Components)
	{
		component->Velocity += component->Acceleration * deltaTime;

		component->Velocity.Clamp(-MAX_VELOCITY, MAX_VELOCITY);

		double speedX = component->Velocity.x;
		double speedY = component->Velocity.y / 2;

		component->Position += Vec2<double>(speedX, speedY) * deltaTime;

		// check for bounces on left and right
		if ((component->Position.x > GAME_WIDTH && component->Velocity.x > 0)
			|| (component->Position.x < 0 && component->Velocity.x < 0)) {
			component->Velocity.x = component->Velocity.x * -1;
		}

		// tp from top to bottom and bottom to top
		if (component->Position.y > GAME_HEIGHT || component->Position.y < 0) {
			component->Position.y = fmod(component->Position.y + (double)GAME_HEIGHT, GAME_HEIGHT);
		}
	}

}


#pragma once
#include "IEntity.h" // neded for extention
#include "PhysicComponent.h" // need for vector
#include "DrawComponent.h"

// forward declaration
class GameWorld;
class PhysicComponent;
class ColliderComponent;
class Inputs;
class ASCIIRenderer;

// class definition
class Starship : public IEntity
{
public:
	void Init(GameWorld* world, float startX, float startY, float velX, float velY);

	void Update(float deltaTime);

	void Shoot();

	void HandleCollision(ColliderComponent* other);

	Starship(float x, float y);

	~Starship();

private:
	PhysicComponent* m_physic;
	DrawComponent* m_draw;
	ColliderComponent* m_collider;
	Inputs* m_keyboard;

	float startX, startY;
};
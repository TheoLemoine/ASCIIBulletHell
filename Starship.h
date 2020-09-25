#pragma once
#include "IEntity.h"
#include <stdio.h>

class GameWorld;
class Inputs;
struct ColliderComponent;
struct PhysicComponent;
struct DrawComponent;


//[event_receiver(native)]
class Starship : public IEntity
{
public:
	void Init(GameWorld* world, double startX, double startY, double velX, double velY);

	void Update(float deltaTime);

	void Shoot();

	void HandleCollision(ColliderComponent* other);

	Starship(float x, float y);

	~Starship();

private:
	PhysicComponent* m_physic;
	ColliderComponent* m_collider;
	DrawComponent* m_draw;
	Inputs* m_keyboard;
	GameWorld* m_world;

	float startX, startY;
	float m_lastShoot;
};
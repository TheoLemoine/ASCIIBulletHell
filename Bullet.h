#pragma once
#include "IEntity.h"
#include <stdio.h>

class GameWorld;
struct ColliderComponent;
struct DrawComponent;
struct PhysicComponent;


//[event_receiver(native)]
class Bullet : public IEntity
{
public:
	void Init(GameWorld* world, double startX, double startY, double velX, double velY);
	void Update(float deltaTime);
	void HandleCollision(ColliderComponent* other);

private:
	PhysicComponent* m_physic;
	DrawComponent* m_draw;
	ColliderComponent* m_collider;
	GameWorld* m_world;
};


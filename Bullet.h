#pragma once
#include "IEntity.h"

//Forward declaration
class GameWorld;
class PhysicComponent;
class DrawComponent;
class ColliderComponent;

class Bullet :
    public IEntity
{
public:
	void Init(GameWorld* world, float startX, float startY, float velX, float velY);
	void Update(float deltaTime);

private:
	PhysicComponent* m_physic;
	DrawComponent* m_draw;
	ColliderComponent* m_collider;
};


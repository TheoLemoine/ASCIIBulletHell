#pragma once
#include "Entity.h"

class GameWorld;
struct ColliderComponent;
struct DrawComponent;
struct PhysicComponent;


class Bullet : public Entity
{
public:
	// lifecycle
	void Init(GameWorld* world, double startX, double startY, double velX, double velY);
	void Update(float deltaTime);
	void Delete();

	// other methods
	void HandleCollision(ColliderComponent* other);

	// constructor and destructor
	Bullet();
	~Bullet();

private:
	PhysicComponent* m_physic;
	DrawComponent* m_draw;
	ColliderComponent* m_collider;
	GameWorld* m_world;
};


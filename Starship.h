#pragma once
#include "Entity.h"

class GameWorld;
class Inputs;
struct ColliderComponent;
struct PhysicComponent;
struct DrawComponent;


class Starship : public Entity
{
public:
	// lifecycle
	void Init(GameWorld* world, double startX, double startY, double velX, double velY);
	void Update(float deltaTime);
	void Delete();

	// other methods
	void Shoot();
	void HandleCollision(ColliderComponent* other);

	// constructor and destructor
	Starship();
	~Starship();

private:
	PhysicComponent* m_physic;
	ColliderComponent* m_collider;
	DrawComponent* m_draw;
	Inputs* m_keyboard;

	float m_lastShoot;
};
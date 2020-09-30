#pragma once
#include "Constants.h"
#include <vector>
#include <functional>

struct PhysicComponent;
struct ColliderComponent;

typedef std::function<void(ColliderComponent*)> CollisionCallback;


struct ColliderComponent
{
public:
	PhysicComponent* Physic;
	double Size;
	Tag ComponentTag;
	ColliderComponent(PhysicComponent*, double size, Tag);
	void AddCollisionListener(CollisionCallback);
	void TriggerCollision(ColliderComponent*);

private:
	std::vector<CollisionCallback> m_callbacks;
};


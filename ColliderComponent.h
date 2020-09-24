#pragma once
//Forward declaration
struct PhysicComponent;
class IEntity;

class ColliderComponent
{
public:
	PhysicComponent* Physic;
	IEntity* Entity;
	float Size;
	enum Tag { SPACESHIP, PROJECTILE, ENNEMY };
	Tag myTag;
	ColliderComponent(IEntity* gameobject, PhysicComponent* physics, float size, Tag tag);
	void Collision(Tag colliderTag);
	bool Collide(ColliderComponent collider);
};


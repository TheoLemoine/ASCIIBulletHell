#pragma once
//Forward declaration
class PhysicComponent;
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
};


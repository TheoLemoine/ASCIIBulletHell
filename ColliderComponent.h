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
	bool Colide(const ColliderComponent& collider)
	{
		if (Physic->Dist(collider.Physic) <= Size + collider.Size)
			return true;
	}
};


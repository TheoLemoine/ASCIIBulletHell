#include "IEntity.h"
#include "PhysicComponent.h"
#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(IEntity* gameobject, PhysicComponent* physics, float size, Tag tag)
{
	Entity = gameobject;
	Physic = physics;
	Size = size;
	myTag = tag;
}

void ColliderComponent::Collision(ColliderComponent::Tag colliderTag)
{
	//TODO WARNING IF WE ADD OBJECT TAG MAYBE DO MATRICE
	switch (myTag)
	{
	case SPACESHIP:
		switch (colliderTag)
		{
		case PROJECTILE:
		case ENNEMY:
			//TODO LOSS LIFE
			break;
		case SPACESHIP:
			//IMPOSSIBLE
			break;
		}
		break;
	case PROJECTILE:
		switch (colliderTag)
		{
		case SPACESHIP:
		case ENNEMY:
			//TODO DESTROY
			break;
		case PROJECTILE:
			//DO NOTHING
			break;
		}
		break;
	case ENNEMY:
		switch (colliderTag)
		{
		case SPACESHIP:
		case PROJECTILE:
			//TODO LOSS LIFE
			break;
		case ENNEMY:
			//DO NOTHING
			break;
		}
		break;
	}
}

bool ColliderComponent::Collide(ColliderComponent collider)
{
	return (Physic->Dist(*collider.Physic) <= Size + collider.Size);
}

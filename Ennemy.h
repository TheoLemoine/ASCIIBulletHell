#pragma once
#include "IEntity.h"
class GameWorld;
class PhysicComponent;
class ColliderComponent;
class DrawComponent;


class Ennemy :
    public IEntity
{
public :
    // Hérité via IEntity
    virtual void Init(GameWorld* world, float startX, float startY, float velX, float velY) override;

    virtual void Update(float deltaTime) override;

    PhysicComponent* m_physic;
    ColliderComponent* m_collider;
    DrawComponent* m_draw;
};


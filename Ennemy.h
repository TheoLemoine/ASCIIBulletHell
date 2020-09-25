#pragma once
#include "IEntity.h"

class GameWorld;
struct PhysicComponent;
struct ColliderComponent;
struct DrawComponent;


class Ennemy :
    public IEntity
{
public :
    virtual void Init(GameWorld* world, double startX, double startY, double velX, double velY) override;

    virtual void Update(float deltaTime) override;

    PhysicComponent* m_physic;
    ColliderComponent* m_collider;
    DrawComponent* m_draw;
};


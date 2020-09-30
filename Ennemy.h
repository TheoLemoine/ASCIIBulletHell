#pragma once
#include "Entity.h"

class GameWorld;
struct PhysicComponent;
struct ColliderComponent;
struct DrawComponent;


class Ennemy : public Entity
{
public :
    // lifecycle
    void Init(GameWorld* world, double startX, double startY, double velX, double velY) override;
    void Update(float deltaTime) override;
    void Delete() override;

    // other methods
    void HandleCollision(ColliderComponent* other);

    // constructor and destructor
    Ennemy();
    ~Ennemy();

private:
    GameWorld* m_world;
    PhysicComponent* m_physic;
    ColliderComponent* m_collider;
    DrawComponent* m_draw;
};


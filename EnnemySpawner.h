#pragma once
#include "Entity.h"

class GameWorld;


class EnnemySpawner : public Entity
{
public:
    // lifecycle
    void Init(GameWorld* world, double startX, double startY, double velX, double velY) override;
    void Update(float deltaTime) override;
    void Delete() override;

    EnnemySpawner(float coolDown);
    ~EnnemySpawner();

private:
    float m_currentSpawnCoolDown;
    float m_spawnCoolDown;

};


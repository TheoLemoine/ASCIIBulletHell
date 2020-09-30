#pragma once
#include "Entity.h"
#include "Vec2.h"
#include <vector>
#include <utility>

struct PhysicComponent;
struct DrawComponent;


class Particles : public Entity
{
public:
    // lifecycle
    void Init(GameWorld* world, double startX, double startY, double velX, double velY) override;
    void Update(float deltaTime) override;
    void Delete() override;

    Particles(std::vector<char> sprites, int color, int nbParticles, double force, float duration, Vec2 baseVelocity);
    ~Particles();

private:
    std::vector<char> m_sprites;
    int m_color;
    int m_nbParticles;
    double m_force;
    float m_duration;
    float m_lifetime;
    Vec2 m_baseVelocity;

    std::vector<std::pair<PhysicComponent*, DrawComponent*>> m_particles;
};


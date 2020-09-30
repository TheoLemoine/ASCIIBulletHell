// header file
#include "Particles.h"

#include "GameWorld.h"
#include "PhysicSystem.h"
#include "PhysicComponent.h"
#include "DrawSystem.h"
#include "DrawComponent.h"
#include "Constants.h"
#include <vector>
#include <utility>


void Particles::Init(GameWorld* world, double startX, double startY, double velX, double velY)
{
	m_world = world;

	for (int i = 0; i < m_nbParticles; ++i) 
	{
		PhysicComponent* physic = m_world->Physics->RequestComponent(
			startX, startY,
			m_baseVelocity.x + (randFloat(-m_force, m_force)),
			m_baseVelocity.y + (randFloat(-m_force, m_force))
		);
		DrawComponent* drawer = m_world->Drawer->RequestComponent(
			physic, 
			{ { m_sprites[rand() % m_sprites.size()] } }, // random char of the list
			{ { m_color } },
			1, 1, 0.f
		);

		auto particle = std::make_pair(physic, drawer);

		m_particles.push_back(particle);
	}
}

void Particles::Update(float deltaTime)
{
	m_lifetime += deltaTime;

	if (m_lifetime > m_duration) {
		m_world->AddToTrashcan(this);
	}
}

void Particles::Delete()
{
	auto end_itr = m_particles.end();
	for (auto itr = m_particles.begin(); itr != end_itr; ++itr) 
	{
		auto particle = *itr;
		m_world->Physics->DeleteComponent(particle.first);
		m_world->Drawer->DeleteComponent(particle.second);
	}
}

Particles::Particles(std::vector<char> sprites, int color, int nbParticles, double force, float duration, Vec2 baseVelocity = Vec2(0, 0))
{
	m_sprites = sprites;
	m_color = color;
	m_nbParticles = nbParticles;
	m_force = force;

	m_duration = duration;
	m_lifetime = 0.f;

	m_baseVelocity = baseVelocity;
	m_particles = std::vector<std::pair<PhysicComponent*, DrawComponent*>>(nbParticles);
}

Particles::~Particles() { }

#include "GameWorld.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "DrawComponent.h"
#include "DrawSystem.h"


#include "Bullet.h"

void Bullet::Init(GameWorld* world, float startX,float startY)
{
	m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);
	m_draw = world->Drawer->RequestComponent(m_physic, 'V');
}

void Bullet::Update(float deltaTime)
{
}

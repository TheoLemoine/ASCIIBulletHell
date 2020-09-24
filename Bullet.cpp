#include "GameWorld.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include <Windows.h>

#include "Bullet.h"

constexpr int A_BLCK = 0x00;
constexpr int D_BLUE = FOREGROUND_BLUE;
constexpr int B_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

void Bullet::Init(GameWorld* world, float startX,float startY)
{
	m_physic = world->Physics->RequestComponent(startX, startY, 0, 0);
	m_draw = world->Drawer->RequestComponent(m_physic,
		// sprites
		{
			{
				' ', '^', ' ',
				'/', '|','\\',
				' ', '|', ' ',
			},
			{
				' ', '^', ' ',
			   '\'', '|','\'',
				' ','\'', ' ',
			},
		},
		// colors
		{
			{
				A_BLCK, B_BLUE, A_BLCK,
				B_BLUE, B_BLUE, B_BLUE,
				A_BLCK, B_BLUE, A_BLCK,
			},
			{
				A_BLCK, B_BLUE, A_BLCK,
				D_BLUE, B_BLUE, D_BLUE,
				A_BLCK, D_BLUE, A_BLCK,
			},
		},
	3, 3, 1.5);
}

void Bullet::Update(float deltaTime)
{
}

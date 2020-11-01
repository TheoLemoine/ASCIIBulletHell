// header file
#include "Starship.h"
// other entities
#include "Bullet.h"
#include "Particles.h"
#include "UIEndText.h"
// components and systems
#include "ColliderSystem.h"
#include "ColliderComponent.h"
#include "DrawComponent.h"
#include "DrawSystem.h"
#include "DrawTextComponent.h"
#include "DrawTextSystem.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "SoundSystem.h"
// game utility
#include "GameWorld.h"
#include "Inputs.h"
#include "Entity.h"
#include "Constants.h"
// external deps
#include <Windows.h>
#include <functional>
#include <iostream>


void Starship::Init(GameWorld* world, double startX, double startY, double velX, double velY) {
	m_world = world;

	m_physic = m_world->Physics->RequestComponent(startX, startY, 0, 0);

	m_collider = m_world->Colliders->RequestComponent(m_physic, 2, Tag::SPACESHIP);
	// bind collision event
	m_collider->AddCollisionListener(std::bind(&Starship::HandleCollision, this, std::placeholders::_1));

	m_draw = m_world->Drawer->RequestComponent(m_physic,
		// animation sprites
		{ 
			{
				' ', ' ', '^', ' ', ' ',
				' ', '/', 'H','\\', ' ',
				'/', 'd', 'W', 'b','\\',
				' ', '"', ' ', '"', ' ',
			},
			{
				' ', ' ', '^', ' ', ' ',
				' ', '/', 'H','\\', ' ',
				'/', 'd', 'W', 'b','\\',
				' ', 'W', ' ', 'W', ' ',
			},
			{
				' ', ' ', '^', ' ', ' ',
				' ', '/', 'H','\\', ' ',
				'/', 'd', 'W', 'b','\\',
				' ', 'w', ' ', 'w', ' ',
			}
		}, 
		// animation colors
		{ 
			{
				A_BLCK, A_BLCK, D_CYAN, A_BLCK, A_BLCK,
				A_BLCK, D_CYAN, B_CYAN, D_CYAN, A_BLCK,
				D_CYAN, B_CYAN, B_CYAN, B_CYAN, D_CYAN,
				A_BLCK, D_PRPL, A_BLCK, D_PRPL, A_BLCK,
			},
			{
				A_BLCK, A_BLCK, D_CYAN, A_BLCK, A_BLCK,
				A_BLCK, D_CYAN, B_CYAN, D_CYAN, A_BLCK,
				D_CYAN, B_CYAN, B_CYAN, B_CYAN, D_CYAN,
				A_BLCK, B_PRPL, A_BLCK, B_PRPL, A_BLCK,
			},
			{
				A_BLCK, A_BLCK, D_CYAN, A_BLCK, A_BLCK,
				A_BLCK, D_CYAN, B_CYAN, D_CYAN, A_BLCK,
				D_CYAN, B_CYAN, B_CYAN, B_CYAN, D_CYAN,
				A_BLCK, B_PRPL, A_BLCK, B_PRPL, A_BLCK,
			}
		},
	5, 4, 2);

	m_healthBar = m_world->TextDrawer->RequestComponent(Vec2<unsigned int>(0, 0), "###", B_CYAN);

	m_keyboard = m_world->Keyboard;
}

void Starship::Update(float deltaTime) {
	m_physic->Acceleration.y = 0;
	m_physic->Acceleration.x = 0;

	if (m_physic->Velocity.Dist(Vec2<double>(0, 0)) <= SS_IMMOBILITY)
		m_physic->Velocity = Vec2<double>(0, 0);

	float down = m_keyboard->DownPress();
	float up = m_keyboard->UpPress();
	float right = m_keyboard->RightPress();
	float left = m_keyboard->LeftPress();

	//if(downed != 0 || lefted != 0 || righted != 0 || uped != 0)
	//std::cout << "down : " << downed << std::endl << "up : " << uped << std::endl << "right : " << righted << std::endl << "left : " << lefted << std::endl;



	//Accelerate up and down
	if (down != 0 || (m_physic->Velocity.y < 0 && up == 0))
		m_physic->Acceleration.y = SS_ACCELERATION_POWER * down;
	if (up != 0 || (m_physic->Velocity.y > 0 && down == 0))
		m_physic->Acceleration.y = -SS_ACCELERATION_POWER * up;

	//Accelerate right and left
	if (left != 0 || (m_physic->Velocity.x > 0 && right == 0))
		m_physic->Acceleration.x = -SS_ACCELERATION_POWER * left;
	if (right != 0 || (m_physic->Velocity.x < 0 && left == 0))
		m_physic->Acceleration.x = SS_ACCELERATION_POWER * right;
	
	//Deccelerate
	if (left == 0 && right == 0 && up == 0 && down == 0)
		m_physic->Acceleration = m_physic->Velocity * -1;

	m_lastShoot -= deltaTime;
	//Shoot
	if (m_keyboard->SpacePress() && m_lastShoot <=0)
	{
		Shoot();
		m_lastShoot = SS_COOLDOWN;
	}
}

void Starship::Delete() {

	// ask systems to delete linked components
	m_world->Physics->DeleteComponent(m_physic);
	m_world->Drawer->DeleteComponent(m_draw);
	m_world->TextDrawer->DeleteComponent(m_healthBar);
	m_world->Colliders->DeleteComponent(m_collider);
}

void Starship::Shoot()
{
	//TODO INVOKE BULLET
	Vec2<double> bulletPos = m_physic->Position + SS_SHOOT_POS;
	float spread = randFloat(-SS_SPREAD_RATIO, SS_SPREAD_RATIO);
	Vec2<double> bulletSpeed = Vec2<double>(
		m_physic->Velocity.x / SS_BULLET_RATIO_SPEED + spread,
		m_physic->Velocity.y / SS_BULLET_RATIO_SPEED + BLT_SPEED
	);

	Bullet* bullet = new Bullet();
	bullet->Init(m_world, bulletPos.x, bulletPos.y, bulletSpeed.x, bulletSpeed.y);
	m_world->AddEntity(bullet);

}

void Starship::HandleCollision(ColliderComponent* other) 
{

	m_hp--;

	// low sound for 'player got hit'
	m_world->Sound->AsyncBeep(260, 600);

	// recreate health bar
	m_healthBar->m_content = "";
	for (int i = 0; i < m_hp; i++)
	{
		m_healthBar->m_content += "#";
	}

	// die with lots of particles
	if (m_hp <= 0) 
	{

		m_world->AddToTrashcan(this);

		// and handle dying
		Particles* particleSystemOut = new Particles({ '.', '*', '0', 'o' }, B_CYAN, 30, 2, 15.f, m_physic->Velocity);
		particleSystemOut->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
		m_world->AddEntity(particleSystemOut);

		Particles* particleSystemCenter = new Particles({ '#', '@', '&' }, B_PRPL, 10, 0.5, 30.f, m_physic->Velocity);
		particleSystemCenter->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
		m_world->AddEntity(particleSystemCenter);

		UIEndText* endText = new UIEndText();
		endText->Init(m_world, GAME_WIDTH / 2, GAME_HEIGHT / 2, 0, 0);
		m_world->AddEntity(endText);
	}
	else
	{
		// and handle dying
		Particles* particleSystemOut = new Particles({ '@', '#', '*', '0', 'o' }, B_CYAN, 5, 1.2, 5.f, m_physic->Velocity);
		particleSystemOut->Init(m_world, m_physic->Position.x, m_physic->Position.y, 0, 0);
		m_world->AddEntity(particleSystemOut);
	}
	
}

Starship::Starship() {
	// set on Init()
	m_world = nullptr;
	m_physic = nullptr;
	m_collider = nullptr;
	m_keyboard = nullptr;
	m_draw = nullptr;

	m_lastShoot = 0.f;
	m_hp = SS_HP;
}

Starship::~Starship() { }
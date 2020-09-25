#pragma once
#include "Vec2.h"
#include <Windows.h>


const unsigned int GAME_WIDTH = 120;
const unsigned int GAME_HEIGHT = 60;

const double MAX_VELOCITY = 20;
const double ACCELERATION_POWER = 10;

//SPACESHIP
const double SS_ACCELERATION_POWER = 7.5;
const double SS_SIZE = 2;
const Vec2  SS_SHOOT_POS = Vec2(0, -2);
const double SS_COOLDOWN = 2;
const double SS_IMMOBILITY = 0.01;
const double SS_BULLET_RATIO_SPEED = 2;

//BULLET
const double BULLET_SPEED = -2.5;

//COLLIDER
enum class Tag : unsigned int { 
	SPACESHIP = 0, 
	PROJECTILE = 1, 
	ENNEMY  = 2
};

// collision in index of both tags show if they collide or not.
const bool COLLISION_MATRIX[3][3] = {
	{ false, true,  true,  },
	{ true,  false, true,  },
	{ true,  true,  false, },
};

constexpr int A_BLCK = 0x00; // all		black
constexpr int B_CYAN = 0x0B; // bright	cyan
constexpr int D_CYAN = 0x03; // dark	cyan
constexpr int B_PRPL = 0x0D; // bright	purple
constexpr int D_PRPL = 0x05; // dark	purple
constexpr int D_BLUE = 0x01; // dark	blue
constexpr int B_BLUE = 0x09; // bright	blue
constexpr int B_RED  = 0x03; // bright	red

//ENEMYS
const float SPAWN_COOLDOWN = 10;
#pragma once
#include "Vec2.h"
#include <Windows.h>

#define randFloat(HI, LO) LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)))

const bool SHOW_FPS = true;

const unsigned int GAME_WIDTH = 120;
const unsigned int GAME_HEIGHT = 60;

const double MAX_VELOCITY = 20;

//SPACESHIP
const int SS_HP = 3;
const double SS_ACCELERATION_POWER = 5;
const double SS_SIZE = 2;
const Vec2  SS_SHOOT_POS = Vec2(0, -2);
const double SS_COOLDOWN = 2;
const double SS_IMMOBILITY = 0.1;
const double SS_BULLET_RATIO_SPEED = 2;
const float SS_SPREAD_RATIO = 0.1f;

//BULLET
const double BLT_SPEED = -2.5;
const float BLT_TIME_BEFORE_TAG_SWAP = 20.f;

//ENNEMIES
const float ENMY_SPAWN_COOLDOWN = 10;
const int ENMY_SCORE_VALUE = 5;

//COLLIDER
enum class
	Tag : unsigned int {
	SPACESHIP = 0,
	ENNEMY = 1,
	NEW_PROJECTILE = 2,
	PROJECTILE = 3
};

// collision in index of both tags show if they collide or not.
const bool COLLISION_MATRIX[4][4] = {
	{ false, true,  false, true  },
	{ true,  false, true, true },
	{ false,  true,  false, false },
	{ true,  true,  false, false }
};

constexpr int A_BLCK = 0x00; // all		black
constexpr int B_CYAN = 0x0B; // bright	cyan
constexpr int D_CYAN = 0x03; // dark	cyan
constexpr int B_PRPL = 0x0D; // bright	purple
constexpr int D_PRPL = 0x05; // dark	purple
constexpr int B_YLOW = 0x0E; // bright	purple
constexpr int D_YLOW = 0x06; // dark	purple
constexpr int B_BLUE = 0x09; // bright	blue
constexpr int D_BLUE = 0x01; // dark	blue
constexpr int B__RED = 0x0C; // bright	red
constexpr int D__RED = 0x04; // dark	red
constexpr int B_GREN = 0x0A; // bright	green
constexpr int D_GREN = 0x02; // dark	green

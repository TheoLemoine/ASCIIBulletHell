#pragma once
#include "Vec2.h"


const int GAME_WIDTH = 120;
const int GAME_HEIGHT = 60;

const float MAX_VELOCITY = 20;

//SPACESHIP
const float SS_ACCELERATION_POWER = 10;
const float SS_SIZE = 2;
const Vec2 SS_SHOOT_POS = Vec2(0,2);

//BULLET
const float BULLET_SPEED = 10;

//COLLIDER
enum Tag { 
	SPACESHIP = 0, 
	PROJECTILE, 
	ENNEMY 
};

// collision in index of both tags show if they collide or not.
const bool COLLISION_MATRIX[3][3] = {
	{ false, true,  true,  },
	{ true,  false, true,  },
	{ true,  true,  false, },
};
const float ACCELERATION_POWER = 10;
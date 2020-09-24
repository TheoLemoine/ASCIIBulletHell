#pragma once


const int GAME_WIDTH = 120;
const int GAME_HEIGHT = 60;

const float MAX_VELOCITY = 20;



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
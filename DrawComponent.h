#pragma once
#include <vector>

struct PhysicComponent;


struct DrawComponent
{
public:
	DrawComponent(
		PhysicComponent* physic, 
		std::vector<std::vector<char>> charMaps,
		std::vector<std::vector<int>> colorMaps,
		unsigned int width, unsigned int height, float period
	);

	PhysicComponent* Physic;

	// dimentions of the sprite
	int Width;
	int Height;

	// animation
	unsigned int currentFrame;
	float framePeriod;
	float frameTime;

	// data of the sprite
	std::vector<std::vector<char>> CharMaps;
	std::vector<std::vector<int>> ColorMaps;

};


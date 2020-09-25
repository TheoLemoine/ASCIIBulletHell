// header file
#include "DrawComponent.h"

#include "PhysicComponent.h"
#include <vector>


DrawComponent::DrawComponent(
	PhysicComponent* physic,
	std::vector<std::vector<char>> charMaps,
	std::vector<std::vector<int>> colorMaps,
	unsigned int width, unsigned int height, float period
) {
	Physic = physic;

	CharMaps = charMaps;
	ColorMaps = colorMaps;
	Width = width;
	Height = height;

	currentFrame = 0;
	framePeriod = period;
	frameTime = 0;
}

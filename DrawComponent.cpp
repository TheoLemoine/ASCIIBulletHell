// header file
#include "DrawComponent.h"
// dependencies
#include "PhysicComponent.h"
// external dependencies
#include <vector>

DrawComponent::DrawComponent(
	PhysicComponent* physic,
	std::vector<std::vector<char>> charMaps,
	std::vector<std::vector<int>> colorMaps,
	int width, int height, float period
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

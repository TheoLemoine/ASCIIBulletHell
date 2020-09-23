#pragma once
#include <vector>


// forward definition
struct DrawComponent;
struct PhysicComponent;
class ASCIIRenderer;

// class definition
class DrawSystem
{

public:
	DrawSystem(ASCIIRenderer* renderer);

	std::vector<DrawComponent*> Components;

	DrawComponent* RequestComponent(
		PhysicComponent* physic,
		std::vector<std::vector<char>> charMaps,
		std::vector<std::vector<int>> colorMaps,
		int width, int height, float period
	);
	void UpdateComponents(float deltaTime);

private:
	ASCIIRenderer* m_renderer;

};


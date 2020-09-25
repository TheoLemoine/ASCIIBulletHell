#pragma once
#include <vector>

class ASCIIRenderer;
struct DrawComponent;
struct PhysicComponent;


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
	void DeleteComponent(DrawComponent* componentPointer);
	void UpdateComponents(float deltaTime);

private:
	ASCIIRenderer* m_renderer;

};


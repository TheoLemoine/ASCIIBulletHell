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

	std::vector<DrawComponent> Components;

	DrawComponent* RequestComponent(PhysicComponent* physic, char sprite);
	void UpdateComponents();

private:
	ASCIIRenderer* m_renderer;

};


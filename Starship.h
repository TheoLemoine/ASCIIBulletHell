#pragma once
#include "IEntity.h" // neded for extention
#include "PhysicComponent.h" // need for vector

// forward declaration
class GameWorld;
class PhysicComponent;
class Inputs;
class ASCIIRenderer;

// class definition
class Starship : public IEntity
{
public:
	void Init(GameWorld* world);

	void Update(float deltaTime);

	Starship(float x, float y);

	~Starship();

private:
	PhysicComponent* m_physic;
	Inputs* m_keyboard;
	ASCIIRenderer* m_renderer;

	float startX, startY;
};
#pragma once
#include <vector>


// forward declarations
class PhysicSystem;
class ASCIIRenderer;
class GameClock;
class Inputs;
class IEntity;

// class definition
class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard);
	~GameWorld();

	PhysicSystem* Physics;
	ASCIIRenderer* Renderer;
	GameClock* Clock;
	Inputs* Keyboard;
	std::vector<IEntity*> Entities;

	void InitWorld();
	void StartGameLoop();

};
#pragma once

// class containing all objects and components to render
class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard);

	PhysicSystem* Physics;
	ASCIIRenderer* Renderer;
	GameClock* Clock;
	Inputs* Keyboard;
	std::vector<IEntity> Entities;

	void InitWorld();
	void StartGameLoop();

};
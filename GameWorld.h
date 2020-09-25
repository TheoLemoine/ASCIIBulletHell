#pragma once
#include <vector>

class ASCIIRenderer;
class GameClock;
class Inputs;
class ColliderSystem;
class DrawSystem;
class PhysicSystem;
class IEntity;


class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard);
	~GameWorld();

	PhysicSystem* Physics;
	DrawSystem* Drawer;
	ColliderSystem* Colliders;
	ASCIIRenderer* Renderer;
	GameClock* Clock;
	Inputs* Keyboard;
	std::vector<IEntity*> Entities;

	void InitWorld();
	void StartGameLoop();
	IEntity* AddEntity(IEntity *entity);
	void DeleteEntity(IEntity* entity);
};
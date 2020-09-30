#pragma once
#include <vector>
#include <stack>

class ASCIIRenderer;
class GameClock;
class Inputs;
class Score;
class ColliderSystem;
class DrawSystem;
class PhysicSystem;
class Entity;


class GameWorld {

public:
	GameWorld(ASCIIRenderer* renderer, GameClock* clock, Inputs* keyboard, Score* scoreBoard);
	~GameWorld();

	PhysicSystem* Physics;
	DrawSystem* Drawer;
	ColliderSystem* Colliders;
	ASCIIRenderer* Renderer;
	GameClock* Clock;
	Inputs* Keyboard;
	Score* ScoreBoard;
	std::vector<Entity*> Entities;

	void InitWorld();
	void StartGameLoop();
	Entity* AddEntity(Entity* entity);
	void AddToTrashcan(Entity* entity);

private:
	// vector of index of Enities to delete at the end of the frame
	// deleting entities immediatly might cause disfunction in the currents systems loops
	std::stack<Entity*> m_trashcan;

	void EmptyTrashcan();
};
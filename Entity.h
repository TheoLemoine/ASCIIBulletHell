#pragma once

class GameWorld;

/*
	
Entity defines lifecycle methods for Entities in the world

*/
class Entity {

public:
	virtual void Init(GameWorld* world, double startX, double startY, double velX, double velY) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Delete() = 0;

protected:
	GameWorld* m_world;
};
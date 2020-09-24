#pragma once


// forward declaration
class GameWorld;

// class definition
class IEntity {

public:
	virtual void Init(GameWorld* world, float startX, float startY, float velX, float velY) = 0;
	virtual void Update(float deltaTime) = 0;
};
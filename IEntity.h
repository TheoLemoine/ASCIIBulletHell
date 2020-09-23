#pragma once


// forward declaration
class GameWorld;

// class definition
class IEntity {

public:
	virtual void Init(GameWorld* world) = 0;
	virtual void Update(float deltaTime) = 0;
};
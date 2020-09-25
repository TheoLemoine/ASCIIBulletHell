#pragma once

class GameWorld;


// class definition
class IEntity {

public:
	virtual void Init(GameWorld* world, double startX, double startY, double velX, double velY) = 0;
	virtual void Update(float deltaTime) = 0;
};
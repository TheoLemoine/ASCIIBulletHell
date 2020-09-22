#pragma once
#include "GameWorld.h"

class GameWorld;

class IEntity {

public:
	virtual void Init(GameWorld* world) = 0;
	virtual void Update(float deltaTime) = 0;

};
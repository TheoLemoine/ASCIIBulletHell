#pragma once

class IEntity {

public:
	virtual void Init(GameWorld* world) = 0;
	virtual void Update(float deltaTime) = 0;

};
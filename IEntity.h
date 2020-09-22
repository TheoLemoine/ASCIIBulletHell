#pragma once
#include "ASCIIRenderer.h"
#include "Keyboard.h"

class IEntity {

public:
	virtual void Update(ASCIIRenderer* renderer, Keyboard* keyboard, float deltaTime) = 0;

};
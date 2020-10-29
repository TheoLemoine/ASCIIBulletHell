#pragma once
#include "Entity.h"

struct DrawTextComponent;


class UIDebug : public Entity
{
public:

	void Init(GameWorld* world, double startX, double startY, double velX, double velY);
	void Update(float deltaTime);
	void Delete();

private:
	DrawTextComponent* m_fpsDrawer;
};


#pragma once
#include "Entity.h"

struct DrawTextComponent;


class UIEndText : public Entity
{
public:

	void Init(GameWorld* world, double startX, double startY, double velX, double velY);
	void Update(float deltaTime);
	void Delete();

private:
	DrawTextComponent* m_gameOverText;
	DrawTextComponent* m_scoreText;
};

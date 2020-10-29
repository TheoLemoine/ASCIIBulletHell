#include "Entity.h"

struct DrawTextComponent;


class UIScoreText : public Entity
{
public:

	void Init(GameWorld* world, double startX, double startY, double velX, double velY);
	void Update(float deltaTime);
	void Delete();

private:
	DrawTextComponent* m_scoreText;
};

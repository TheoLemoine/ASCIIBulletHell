#include "PhysicSystem.h"
#include "Keyboard.h"
#include "IEntity.h"

class Starship : IEntity
{
public:
	void Init(GameWorld* world);

	void Update(float deltaTime);

	Starship(float x, float y);

	~Starship();

private:
	PhysicComponent* m_physic;
	Keyboard* m_keyboard;

	float startX, startY;
};
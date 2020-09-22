
class Physic
{
public:
	float x, y;
	float xSpeed, ySpeed;
	//TODO COLLIDER

	Physic(float x, float y)
	{
		this->x = x;
		this->y = y;
		xSpeed = 0;
		ySpeed = 0;
	}

	void Move(float deltaTime)
	{
		x += xSpeed * deltaTime;
		y += xSpeed * deltaTime;
	}
};
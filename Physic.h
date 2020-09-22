struct Vec2
{
	float x, y;

	Vec2()
	{
		Vec2(0, 0);
	}

	Vec2(float p_x, float p_y)
	{
		x = p_x;
		y = p_y;
	}

	Vec2 operator * (float val)
	{
		return Vec2(x * val, y * val);
	}

	void operator += (Vec2 val)
	{
		x += val.x;
		y += val.y;
	}
};

class Physic
{
public:
	Vec2 Position;
	Vec2 Speed;
	//TODO COLLIDER with Circle and distance

	Physic(float x, float y)
	{
		Position = Vec2(x,y);
		Speed = Vec2(0, 0);
	}

	void Move(float deltaTime)
	{
		Position += Speed * deltaTime;
	}
};

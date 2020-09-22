#pragma once

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

	Vec2 Clamp(float lower, float upper)
	{
		x = min(upper, max(lower, x));
		y = min(upper, max(lower, y));
	}
};
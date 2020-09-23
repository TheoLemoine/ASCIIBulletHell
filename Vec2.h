#pragma once
#define min(a, b) ((a < b) ? a : b)
#define max(a,b) ((a>b)?a:b)


// struct definition
struct Vec2
{
	float x, y;

	Vec2();
	Vec2(float p_x, float p_y);

	void Clamp(float lower, float upper);
	Vec2 operator * (float val);
	void operator += (Vec2 val);
};
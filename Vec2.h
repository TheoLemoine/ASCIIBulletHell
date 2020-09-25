#pragma once
#include <math.h>


struct Vec2
{
	double x, y;

	Vec2();
	Vec2(double p_x, double p_y);

	void Clamp(double lower, double upper);
	Vec2 operator + (Vec2 val);
	Vec2 operator * (double val);
	void operator += (Vec2 val);
	double Dist(Vec2 target);
};
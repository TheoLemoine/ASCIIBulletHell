// header file
#include "Vec2.h"
// external dependencies
#include <algorithm>

using namespace std;


Vec2::Vec2()
{
	Vec2(0, 0);
}

Vec2::Vec2(float p_x, float p_y)
{
	x = p_x;
	y = p_y;
}

Vec2 Vec2::operator * (float val)
{
	return Vec2(x * val, y * val);
}

Vec2 Vec2::operator + (Vec2 val)
{
	return Vec2(x + val.x, y + val.y);
}

void Vec2::operator += (Vec2 val)
{
	x += val.x;
	y += val.y;
}

void Vec2::Clamp(float lower, float upper)
{
	x = min(upper, max(lower, x));
	y = min(upper, max(lower, y));
}

float Vec2::Dist(Vec2 target)
{
	return sqrt(pow(x - target.x, 2) + pow(y - target.y, 2));
}
// header file
#include "Vec2.h"

#define min(a, b) ((a < b) ? a : b)
#define max(a,b) ((a>b)?a:b)

using namespace std;


Vec2::Vec2()
{
	Vec2(0, 0);
}

Vec2::Vec2(double p_x, double p_y)
{
	x = p_x;
	y = p_y;
}

Vec2 Vec2::operator * (double val)
{
	return Vec2(x * val, y * val);
}

Vec2 Vec2::operator + (Vec2 val)
{
	return Vec2(x + (val.x), y + (val.y));
}

void Vec2::operator += (Vec2 val)
{
	x += val.x;
	y += val.y;
}

void Vec2::Clamp(double lower, double upper)
{
	x = min(upper, max(lower, x));
	y = min(upper, max(lower, y));
}

double Vec2::Dist(Vec2 target)
{
	return sqrt(pow(x - target.x, 2) + pow(y - target.y, 2));
}
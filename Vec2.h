#pragma once
#include <math.h>
#define min(a, b) ((a < b) ? a : b)
#define max(a,b) ((a>b)?a:b)

using namespace std;


template <typename T>
struct Vec2
{
	T x, y;

	Vec2();
	Vec2(T p_x, T p_y);

	void Clamp(T lower, T upper);
	Vec2 operator + (Vec2 val);
	Vec2 operator * (T val);
	void operator += (Vec2 val);
	double Dist(Vec2 target);
};

template <typename T>
Vec2<T>::Vec2()
{
	Vec2(0, 0);
}

template <typename T>
Vec2<T>::Vec2(T p_x, T p_y)
{
	x = p_x;
	y = p_y;
}

template <typename T>
Vec2<T> Vec2<T>::operator * (T val)
{
	return Vec2(x * val, y * val);
}

template <typename T>
Vec2<T> Vec2<T>::operator + (Vec2<T> val)
{
	return Vec2(x + (val.x), y + (val.y));
}

template <typename T>
void Vec2<T>::operator += (Vec2<T> val)
{
	x += val.x;
	y += val.y;
}

template <typename T>
void Vec2<T>::Clamp(T lower, T upper)
{
	x = min(upper, max(lower, x));
	y = min(upper, max(lower, y));
}

template <typename T>
double Vec2<T>::Dist(Vec2<T> target)
{
	return sqrt(pow(x - target.x, 2) + pow(y - target.y, 2));
}
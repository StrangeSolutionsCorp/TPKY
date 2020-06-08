#include "Stone.h"

stone_c* stone_c::create(double x, double y, float m, float s, float a)
{
	static stone_c* real;
	if (!real)
		real = new stone_c(x, y, m, s, a);
	else
		real->fill(x, y, m, s, a);
	return real;
};

stone_c::stone_c(double x, double y, float m, float s, float a)
{
	fill(x, y, m, s, a);
};
void stone_c::fill(double x, double y, float m, float s, float a)
{
	xs = x;
	ys = y;
	mass = m;
	speed = s;
	angle = a;
	xc = xs;
	yc = ys;
	vy = 0;
	vx = 0;
}
#pragma once
class stone_c
{
	stone_c(double x, double y, float m, float s, float a);
public:
	double xs;
	double ys;
	float xc;
	float yc;
	float vy;
	float vx;
	float mass;
	float speed;
	float angle;

	static stone_c* create(double x, double y, float m, float s, float a);
	void fill(double x, double y, float m, float s, float a);
};
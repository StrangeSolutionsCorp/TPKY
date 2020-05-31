#pragma once

#include <SFML/Graphics.hpp>
#include <SFML\Graphics/Text.hpp>
#include "Files.h"
using namespace sf;

#define SW 100
#define SH 100
#define FLOOR 400

class st_ch
{
public:
	Sprite st_s[4];
	Texture st_t[4];
	Image st_i[4];
	Image st_m[4][4];

	int state[4] = { 0,3,0,0 };
	int true_state[4] = { 0,3,0,0 };
	int chf[4] = { 0,1,0,0 };
	Vector2i coord[4];


	st_ch()
	{
		st_i[0].loadFromFile(STP1);
		st_m[0][0].loadFromFile(STP1);
		st_m[0][1].loadFromFile(STP12);
		st_m[0][2].loadFromFile(STP13);
		st_m[0][3].loadFromFile(STP14);
		st_t[0].loadFromImage(st_i[0]);
		st_s[0].setTexture(st_t[0]);
		st_s[0].setPosition(100, FLOOR + 100);
		coord[0].x = 100;

		st_i[1].loadFromFile(STP2);
		st_m[1][0].loadFromFile(STP2);
		st_m[1][1].loadFromFile(STP22);
		st_m[1][2].loadFromFile(STP23);
		st_m[1][3].loadFromFile(STP24);
		st_t[1].loadFromImage(st_i[1]);
		st_s[1].setTexture(st_t[1]);
		st_s[1].setPosition(400, FLOOR + 100);
		coord[1].x = 400;

		st_i[2].loadFromFile(STP3);
		st_m[2][0].loadFromFile(STP3);
		st_m[2][1].loadFromFile(STP32);
		st_m[2][2].loadFromFile(STP33);
		st_m[2][3].loadFromFile(STP34);
		st_t[2].loadFromImage(st_i[2]);
		st_s[2].setTexture(st_t[2]);
		st_s[2].setPosition(700, FLOOR + 100);
		coord[2].x = 700;

		st_i[3].loadFromFile(STP4);
		st_m[3][0].loadFromFile(STP4);
		st_m[3][1].loadFromFile(STP42);
		st_m[3][2].loadFromFile(STP43);
		st_m[3][3].loadFromFile(STP44);
		st_t[3].loadFromImage(st_i[3]);
		st_s[3].setTexture(st_t[3]);
		st_s[3].setPosition(1000, FLOOR + 100);
		coord[3].x = 1000;

		for (int i = 0; i<4; i++)
			coord[i].y = FLOOR+100;
	}

	int isPress(RenderWindow& window, int x, int y, int i, int role);
	Sprite getspr(int i);
	void mouseChange(RenderWindow& window, int x, int y, int i, int role);
	void draw(RenderWindow& window);

};
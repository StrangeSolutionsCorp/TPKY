#define _CRT_SECURE_NO_WARNING

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h> 
#include <dos.h>
#include "Button.h"
#include "Coll.h"
#include "St_ch.h"
#include <SFML\Window/Mouse.hpp>
#include <SFML\Graphics/Text.hpp>
#include "Checker.h"

using namespace sf;

#define PETROL 500
#define FLOOR 400
#define WIGHT 1300
#define HEIGHT 750

class ballista
{
public:
	float x;
	float y;
	int mass;
	float speed;
	float angle;
	float petrol;
};

class stone
{
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
};

String toString(Int64 integer)
{
	std::ostringstream os;
	os << integer;
	return os.str();
}

int main()
{
	if (checker())
	{
		system("pause");
		return 1;
	}
	RenderWindow window(VideoMode(WIGHT, HEIGHT), "TEST");
	int actwind = 0;

	stone Stone;
	ballista Balli1;
	ballista Balli2;

	Image ballista1;
	Image b1_anim[10];
	ballista1.loadFromFile(B11);
	b1_anim[0].loadFromFile(B11);
	b1_anim[1].loadFromFile(B12);
	b1_anim[2].loadFromFile(B13);
	b1_anim[3].loadFromFile(B14);
	b1_anim[4].loadFromFile(B15);
	b1_anim[5].loadFromFile(B16);
	b1_anim[6].loadFromFile(B17);
	b1_anim[7].loadFromFile(B18);
	b1_anim[6].loadFromFile(B19);
	b1_anim[7].loadFromFile(B110);
	Texture bal_t;
	bal_t.loadFromImage(ballista1);
	Sprite bal1_s;
	bal1_s.setTexture(bal_t);
	bal1_s.setPosition(100, FLOOR-50);
	Balli1.x = 100;
	Balli1.y = FLOOR-50;
	Balli1.speed = 0;
	Balli1.angle = 0;
	Balli1.mass = 35;
	Balli1.petrol = PETROL;

	Image deg_1;
	Image d1_anim[6];
	deg_1.loadFromFile(D1);
	d1_anim[0].loadFromFile(D1);
	d1_anim[1].loadFromFile(D11);
	d1_anim[2].loadFromFile(D12);
	d1_anim[3].loadFromFile(D13);
	d1_anim[4].loadFromFile(D14);
	d1_anim[5].loadFromFile(D15);
	Texture d_t;
	d_t.loadFromImage(deg_1);
	Sprite d1_hud;
	d1_hud.setTexture(d_t);
	d1_hud.setPosition(80, 70);

	Image sc_1;
	Image sc1_anim[7];
	sc_1.loadFromFile(S1);
	sc1_anim[0].loadFromFile(S1);
	sc1_anim[1].loadFromFile(S11);
	sc1_anim[2].loadFromFile(S12);
	sc1_anim[3].loadFromFile(S13);
	sc1_anim[4].loadFromFile(S14);
	sc1_anim[5].loadFromFile(S15);
	sc1_anim[6].loadFromFile(S16);
	Texture sc_t;
	sc_t.loadFromImage(sc_1);
	Sprite sc1_hud;
	sc1_hud.setTexture(sc_t);
	sc1_hud.setPosition(80, 170);

	Image ballista2;
	Image b2_anim[10];
	ballista2.loadFromFile(B21);
	b2_anim[0].loadFromFile(B21);
	b2_anim[1].loadFromFile(B22);
	b2_anim[2].loadFromFile(B23);
	b2_anim[3].loadFromFile(B24);
	b2_anim[4].loadFromFile(B25);
	b2_anim[5].loadFromFile(B26);
	b2_anim[6].loadFromFile(B27);
	b2_anim[7].loadFromFile(B28);
	b2_anim[6].loadFromFile(B29);
	b2_anim[7].loadFromFile(B210);
	Texture bal2_t;
	bal2_t.loadFromImage(ballista2);
	Sprite bal2_s;
	bal2_s.setTexture(bal2_t);
	bal2_s.setPosition(1100, FLOOR-50);
	Balli2.x = 1100;
	Balli2.y = FLOOR-50;
	Balli2.speed = 0;
	Balli2.angle = 0;
	Balli2.mass = 35;
	Balli2.petrol = PETROL;

	Image deg_2;
	Image d2_anim[6];
	deg_2.loadFromFile(D2);
	d2_anim[0].loadFromFile(D2);
	d2_anim[1].loadFromFile(D21);
	d2_anim[2].loadFromFile(D22);
	d2_anim[3].loadFromFile(D23);
	d2_anim[4].loadFromFile(D24);
	d2_anim[5].loadFromFile(D25);
	Texture d2_t;
	d2_t.loadFromImage(deg_2);
	Sprite d2_hud;
	d2_hud.setTexture(d2_t);
	d2_hud.setPosition(1100, 70);

	Image sc_2;
	Image sc2_anim[7];
	sc_2.loadFromFile(S2);
	sc2_anim[0].loadFromFile(S2);
	sc2_anim[1].loadFromFile(S21);
	sc2_anim[2].loadFromFile(S22);
	sc2_anim[3].loadFromFile(S23);
	sc2_anim[4].loadFromFile(S24);
	sc2_anim[5].loadFromFile(S25);
	sc2_anim[6].loadFromFile(S26);
	Texture sc2_t;
	sc2_t.loadFromImage(sc_2);
	Sprite sc2_hud;
	sc2_hud.setTexture(sc2_t);
	sc2_hud.setPosition(1150, 170);

	Image stone;
	stone.loadFromFile(ST1);
	Texture stone_t;
	stone_t.loadFromImage(stone);
	Sprite stone_s;
	stone_s.setTexture(stone_t);

	Image fl;
	fl.loadFromFile(FL);
	Texture fl_t;
	fl_t.loadFromImage(fl);
	Sprite fl_s;
	fl_s.setTexture(fl_t);
	fl_s.setPosition(0, FLOOR);
	fl_s.setScale(1.5, 1.5);

	Image sky;
	sky.loadFromFile(SK);
	Texture sky_t;
	sky_t.loadFromImage(sky);
	Sprite sky_s;
	sky_s.setTexture(sky_t);
	sky_s.setPosition(0, 0);

	Image pet1;
	pet1.loadFromFile(P1);
	Texture pet1_t;
	pet1_t.loadFromImage(pet1);
	Sprite pet1_s;
	pet1_s.setTexture(pet1_t);
	pet1_s.setScale(0.025, 0.025);
	pet1_s.setPosition(65, 10);
	Text pet1_text;

	Image pet2;
	pet2.loadFromFile(P2);
	Texture pet2_t;
	pet2_t.loadFromImage(pet2);
	Sprite pet2_s;
	pet2_s.setTexture(pet2_t);
	pet2_s.setScale(0.025, 0.025);
	pet2_s.setPosition(1145, 10);
	Text pet2_text;

	Font font;
	font.loadFromFile(AF);
	pet1_text.setFont(font);
	pet1_text.setString("100");
	pet1_text.setCharacterSize(25);
	pet1_text.setFillColor(sf::Color::Black);
	pet1_text.setPosition(110, 10);
	pet2_text.setFont(font);
	pet2_text.setString("100");
	pet2_text.setCharacterSize(25);
	pet2_text.setFillColor(sf::Color::Black);
	pet2_text.setPosition(1140, 10);

	Image rul;
	rul.loadFromFile(RUL);
	Texture rul_t;
	rul_t.loadFromImage(rul);
	Sprite rul_s;
	rul_s.setTexture(rul_t);
	rul_s.setPosition(250, 50);

	Image w1;
	w1.loadFromFile(W1);
	Texture w1_t;
	w1_t.loadFromImage(w1);
	Sprite w1_s;
	w1_s.setTexture(w1_t);
	w1_s.setPosition(250, 50);

	Image w2;
	w1.loadFromFile(W2);
	Texture w2_t;
	w2_t.loadFromImage(w1);
	Sprite w2_s;
	w2_s.setTexture(w2_t);
	w2_s.setPosition(250, 50);

	Button* Start;
	Start = new Button(500, 100, BU2, BU1, "Test", 200, 100);
	Button* Rules;
	Rules = new Button(500, 225, BU4, BU3, "Test", 200, 100);
	Button* Ex_r;
	Ex_r = new Button(950, 50, BU6, BU5, "Test", 50, 50);
	Button* Ex_g;
	Ex_g = new Button(0, 0, BU6, BU6, "Test", 50, 50);
	Button* Re_g;
	Re_g = new Button(600, FLOOR, BU8, BU7, "Test", 200, 100);

	Vector2i mous;
	Text tecst;

	st_ch st_line;

	double time = 0;
	int shoot_fl = 0;
	bool role = 0;
	int coolider;
	int mode = 0;
	Time t2 = milliseconds(250);
	int mas_res;

	bool draw[11] = {false, true, true, true, true, false, false, true, false, false, false};


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
			{
				window.close();
				break;
			}
			case Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					if ((Ex_g->isPress(window, event.mouseButton.x, event.mouseButton.y)))
					{
						window.close();
						break;
					}
					if (mode == 1)
					{
						for (int i = 0; i < 4; i++)
							if ((mas_res = st_line.isPress(window, mous.x, mous.y, i, role)) > 0)
								if (role == 0)
									Balli1.mass = mas_res;
								else
									Balli2.mass = mas_res;
					}
					else
					{
						if ((mode == 2) || (mode == 3))
						{
							if ((Re_g->isPress(window, event.mouseButton.x, event.mouseButton.y)))
							{
									bal_t.update(ballista1);
									bal1_s.setPosition(100, FLOOR - 50);
									Balli1.x = 100;
									Balli1.y = FLOOR - 50;
									Balli1.speed = 0;
									Balli1.angle = 0;
									Balli1.mass = 35;
									Balli1.petrol = PETROL;
									d_t.update(deg_1);
									d1_hud.setPosition(80, 70);
									sc_t.update(sc_1);
									sc1_hud.setPosition(80, 170);
									bal2_t.update(ballista2);
									bal2_s.setPosition(1100, FLOOR - 50);
									Balli2.x = 1100;
									Balli2.y = FLOOR - 50;
									Balli2.speed = 0;
									Balli2.angle = 0;
									Balli2.mass = 35;
									Balli2.petrol = PETROL;
									d2_t.update(deg_2);
									d2_hud.setPosition(1100, 70);
									sc2_t.update(sc_2);
									sc2_hud.setPosition(1150, 170);
									time = 0;
									shoot_fl = 0;
									role = 0;
									coolider = 0;
									mode = 0;
									mas_res = 35;
									draw[0] = false;
									draw[1] = true;
									draw[2] = true;
									draw[3] = true;
									draw[4] = true;
									draw[5] = false;
									draw[6] = false;
									draw[7] = true;
									draw[8] = false;
									draw[9] = false;
									draw[10] = false;
									st_line.state[0] = 0;
									st_line.state[1] = 3;
									st_line.state[2] = 0;
									st_line.state[3] = 0;
									st_line.true_state[0] = 0;
									st_line.true_state[1] = 3;
									st_line.true_state[2] = 0;
									st_line.true_state[3] = 0;
									st_line.chf[0] = 0;
									st_line.chf[1] = 1;
									st_line.chf[2] = 0;
									st_line.chf[3] = 0;
							}
						}
						else
						{
							if ((Start->isPress(window, event.mouseButton.x, event.mouseButton.y)) && (mode == 0))
							{
								mode = 1;
								draw[3] = draw[4] = false;
							}
							if ((Rules->isPress(window, event.mouseButton.x, event.mouseButton.y)))
							{
								draw[5] = draw[6] = true;
								mode = 4;
							}
							if ((Ex_r->isPress(window, event.mouseButton.x, event.mouseButton.y)))
							{
								draw[5] = draw[6] = false;
								mode = 0;
							}
						}
					}
				}
				break;

			}
			default:
				break;
			}
		}
		if (mode == 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (role == 0)
				{
					if (Balli1.petrol >= 2.5)
					{
						if (Balli1.x >= 1)
						{
							bal1_s.move(-0.5, 0);
							Balli1.x -= 0.5;
						}
						Balli1.petrol -= 2.5;
						pet1_text.setString(toString(Balli1.petrol));
					}
				}
				else if (role == 1)
				{
					if (Balli2.petrol >= 2.5)
					{
						if (Balli2.x >= 1)
						{
							bal2_s.move(-0.5, 0);
							Balli2.x -= 0.5;
						}
						Balli2.petrol -= 2.5;
						pet2_text.setString(toString(Balli2.petrol));
					}
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (role == 0)
				{
					if (Balli1.petrol >= 2.5)
					{
						if (Balli1.x <= 1300)
						{
							bal1_s.move(0.5, 0);
							Balli1.x += 0.5;
						}
						Balli1.petrol -= 2.5;
						pet1_text.setString(toString(Balli1.petrol));
					}
				}
				else if (role == 1)
				{
					if (Balli2.petrol >= 2.5)
					{
						if (Balli1.x <= 1300)
						{
							bal2_s.move(0.5, 0);
							Balli2.x += 0.5;
						}
						Balli2.petrol -= 2.5;
						pet2_text.setString(toString(Balli2.petrol));
					}
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				if (role == 0)
				{
					if (Balli1.speed <= 61)
						Balli1.speed += 0.1;
					if (Balli1.speed == 0)
					{
						bal_t.update(b1_anim[0]);
						sc_t.update(sc1_anim[0]);
					}
					if (Balli1.speed >= 10)
					{
						bal_t.update(b1_anim[1]);
						sc_t.update(sc1_anim[1]);
					}
					if (Balli1.speed >= 20)
					{
						bal_t.update(b1_anim[2]);
						sc_t.update(sc1_anim[2]);
					}
					if (Balli1.speed >= 30)
					{
						bal_t.update(b1_anim[3]);
						sc_t.update(sc1_anim[3]);
					}
					if (Balli1.speed >= 40)
					{
						bal_t.update(b1_anim[4]);
						sc_t.update(sc1_anim[4]);
					}
					if (Balli1.speed >= 50)
					{
						bal_t.update(b1_anim[5]);
						sc_t.update(sc1_anim[5]);
					}
					if (Balli1.speed >= 60)
					{
						sc_t.update(sc1_anim[6]);
					}
					std::cout << "spd++ = " << Balli1.speed << std::endl;
				}
				else if (role == 1)
				{
					if (Balli2.speed <= 60)
						Balli2.speed += 0.1;
					if (Balli2.speed == 0)
					{
						bal2_t.update(b2_anim[0]);
						sc2_t.update(sc2_anim[0]);
					}
					if (Balli2.speed >= 10)
					{
						bal2_t.update(b2_anim[1]);
						sc2_t.update(sc2_anim[1]);
					}
					if (Balli2.speed >= 20)
					{
						bal2_t.update(b2_anim[2]);
						sc2_t.update(sc2_anim[2]);
					}
					if (Balli2.speed >= 30)
					{
						bal2_t.update(b2_anim[3]);
						sc2_t.update(sc2_anim[3]);
					}
					if (Balli2.speed >= 40)
					{
						bal2_t.update(b2_anim[4]);
						sc2_t.update(sc2_anim[4]);
					}
					if (Balli2.speed >= 50)
					{
						bal2_t.update(b2_anim[5]);
						sc2_t.update(sc2_anim[5]);
					}
					if (Balli2.speed >= 60)
					{
						sc2_t.update(sc2_anim[6]);
					}
					std::cout << "spd++ = " << Balli2.speed << std::endl;
				}
				shoot_fl = 1;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (role == 0)
				{
					if (Balli1.angle <= 1.52)
						Balli1.angle += 0.005;
					if ((Balli1.angle >= 0) && (Balli1.angle < 0.21))
						d_t.update(d1_anim[0]);
					if ((Balli1.angle >= 0.21) && (Balli1.angle < 0.65))
						d_t.update(d1_anim[1]);
					if ((Balli1.angle >= 0.65) && (Balli1.angle < 0.79))
						d_t.update(d1_anim[2]);
					if ((Balli1.angle >= 0.79) && (Balli1.angle < 1.15))
						d_t.update(d1_anim[3]);
					if ((Balli1.angle >= 1.15) && (Balli1.angle < 1.32))
						d_t.update(d1_anim[4]);
					if ((Balli1.angle >= 1.32) && (Balli1.angle < 1.5))
						d_t.update(d1_anim[5]);
					if (Balli1.angle >= 1.5)
						d_t.update(d1_anim[0]);
					std::cout << "angle++ = " << Balli1.angle * 57.3 << std::endl;
				}
				else if (role == 1)
				{
					if (Balli2.angle <= 1.52)
						Balli2.angle += 0.005;
					if ((Balli2.angle >= 0) && (Balli2.angle < 0.21))
						d2_t.update(d2_anim[0]);
					if ((Balli2.angle >= 0.21) && (Balli2.angle < 0.65))
						d2_t.update(d2_anim[1]);
					if ((Balli2.angle >= 0.65) && (Balli2.angle < 0.79))
						d2_t.update(d2_anim[2]);
					if ((Balli2.angle >= 0.79) && (Balli2.angle < 1.15))
						d2_t.update(d2_anim[3]);
					if ((Balli2.angle >= 1.15) && (Balli2.angle < 1.32))
						d2_t.update(d2_anim[4]);
					if ((Balli2.angle >= 1.32) && (Balli2.angle < 1.5))
						d2_t.update(d2_anim[5]);
					if (Balli2.angle >= 1.5)
						d2_t.update(d2_anim[0]);
					std::cout << "angle++ = " << Balli2.angle * 57.3 << std::endl;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (role == 0)
				{
					if (Balli1.angle >= 0.006)
						Balli1.angle -= 0.005;
					if ((Balli1.angle >= 0) && (Balli1.angle < 0.21))
						d_t.update(d1_anim[0]);
					if ((Balli1.angle >= 0.21) && (Balli1.angle < 0.65))
						d_t.update(d1_anim[1]);
					if ((Balli1.angle >= 0.65) && (Balli1.angle < 0.79))
						d_t.update(d1_anim[2]);
					if ((Balli1.angle >= 0.79) && (Balli1.angle < 1.15))
						d_t.update(d1_anim[3]);
					if ((Balli1.angle >= 1.15) && (Balli1.angle < 1.32))
						d_t.update(d1_anim[4]);
					if ((Balli1.angle >= 1.32) && (Balli1.angle < 1.5))
						d_t.update(d1_anim[5]);
					if (Balli1.angle >= 1.5)
						d_t.update(d1_anim[0]);
					std::cout << "angle-- = " << Balli1.angle * 57.3 << std::endl;
				}
				else if (role == 1)
				{
					if (Balli2.angle >= 0.006)
						Balli2.angle -= 0.005;
					if ((Balli2.angle >= 0) && (Balli2.angle < 0.21))
						d2_t.update(d2_anim[0]);
					if ((Balli2.angle >= 0.21) && (Balli2.angle < 0.65))
						d2_t.update(d2_anim[1]);
					if ((Balli2.angle >= 0.65) && (Balli2.angle < 0.79))
						d2_t.update(d2_anim[2]);
					if ((Balli2.angle >= 0.79) && (Balli2.angle < 1.15))
						d2_t.update(d2_anim[3]);
					if ((Balli2.angle >= 1.15) && (Balli2.angle < 1.32))
						d2_t.update(d2_anim[4]);
					if ((Balli2.angle >= 1.32) && (Balli2.angle < 1.5))
						d2_t.update(d2_anim[5]);
					if (Balli2.angle >= 1.5)
						d2_t.update(d2_anim[0]);
					std::cout << "angle-- = " << Balli2.angle * 57.3 << std::endl;
				}
			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space))
			{
				if (shoot_fl == 1)
				{
					if (role == 0)
					{
						time = 0;
						Stone.speed = (Balli1.speed * (45.0 / Balli1.mass));
						Stone.angle = Balli1.angle;
						Stone.mass = Balli1.mass;
						Stone.xs = Balli1.x + 100;
						Stone.ys = Balli1.y - 15;
					}
					else if (role == 1)
					{
						time = 0;
						Stone.speed = (Balli2.speed * (45.0 / Balli2.mass));
						Stone.angle = Balli2.angle;
						Stone.mass = Balli2.mass;
						Stone.xs = Balli2.x;
						Stone.ys = Balli2.y - 15;
					}
					stone_s.setPosition(Stone.xs, Stone.ys);
					draw[0] = true;
					Stone.vx = Stone.vy = 0;
					if (role == 0)
						Stone.vx = Stone.speed * cos(Stone.angle);
					else if (role == 1)
						Stone.vx = -(Stone.speed * cos(Stone.angle));
					Stone.vy = Stone.speed * sin(Stone.angle);
					Stone.xc = Stone.yc = 0;
					Stone.xc = Stone.xs + Stone.vx * 0.001;
					Stone.yc = Stone.ys - Stone.vy * 0.001;
					stone_s.setPosition(Stone.xc, Stone.yc);
					if (role == 0)
					{
						if (time == 0)
							bal_t.update(b1_anim[6]);
						if (time == 1.5)
							bal_t.update(b1_anim[7]);
						if (time == 3)
							bal_t.update(b1_anim[8]);
						if (time == 4.5)
							bal_t.update(b1_anim[9]);
					}
					else
					{
						if (time == 0)
							bal2_t.update(b2_anim[6]);
						if (time == 1.5)
							bal2_t.update(b2_anim[7]);
						if (time == 3)
							bal2_t.update(b2_anim[8]);
						if (time == 4.5)
							bal2_t.update(b2_anim[9]);
					}
					time = 0;
					while (Stone.yc <= FLOOR + 15)
					{
						Stone.xc = Stone.xs + (Stone.vx * time);
						Stone.yc = Stone.ys - (Stone.vy * time) + ((9.8 * time * time) / 2);
						stone_s.setPosition(Stone.xc, Stone.yc);
						if (role == 0)
							shoot_fl = collision(&stone_s, &bal2_s, role);
						else
							shoot_fl = collision(&stone_s, &bal1_s, role);
						if (shoot_fl == 1)
						{
							draw[2] = draw[0] = false;
							mode = 2;
							draw[8] = true;
						}
						else if (shoot_fl == 2)
						{
							draw[1] = draw[0] = false;
							mode = 3;
							draw[9] = true;
						}
						window.clear();
						window.draw(sky_s);
						window.draw(fl_s);
						if (draw[1] == true)
							window.draw(bal1_s);
						if (draw[2] == true)
							window.draw(bal2_s);
						if (draw[0] == true)
							window.draw(stone_s);
						window.draw(d1_hud);
						window.draw(d2_hud);
						window.draw(sc1_hud);
						window.draw(sc2_hud);
						window.draw(pet1_s);
						window.draw(pet2_s);
						window.draw(pet1_text);
						window.draw(pet2_text);
						st_line.draw(window);
						if (draw[7] == true)
							window.draw(Ex_g->getspr());
						window.display();
						time += 0.02;
						std::cout << shoot_fl << std::endl;
						if ((Stone.xc <= 0) || (Stone.xc >= WIGHT) || (Stone.yc <= 0))
							break;
					}
					draw[0] = false;
					shoot_fl = 0;
					Balli1.speed = 10;
					Balli1.petrol = PETROL;
					Balli2.speed = 10;
					Balli2.petrol = PETROL;
					if (role == 0)
						role = 1;
					else if (role == 1)
						role = 0;
				}
			}
		}
		pet1_text.setString(toString(Balli1.petrol));
		pet2_text.setString(toString(Balli2.petrol));
		mous = Mouse::getPosition(window);
		Start->mouseChange(window, mous.x, mous.y);
		if ((mode == 0) || (mode == 4))
		{
			Rules->mouseChange(window, mous.x, mous.y);
			Ex_r->mouseChange(window, mous.x, mous.y);
		}
		Ex_g->mouseChange(window, mous.x, mous.y);
		if (mode == 1)
			for (int i = 0; i < 4; i++)
				st_line.mouseChange(window, mous.x, mous.y, i, role);
		window.clear();
		window.draw(sky_s);
		window.draw(fl_s);
		if (draw[1] == true)
			window.draw(bal1_s);
		if (draw[2] == true)
			window.draw(bal2_s);
		if (draw[0] == true)
			window.draw(stone_s);
		if (draw[3] == true)
			window.draw(Start->getspr());
		if (mode == 1)
		{
			window.draw(d1_hud);
			window.draw(d2_hud);
			window.draw(sc1_hud);
			window.draw(sc2_hud);
			window.draw(pet1_s);
			window.draw(pet2_s);
			window.draw(pet1_text);
			window.draw(pet2_text);
			st_line.draw(window);
		}
		if (draw[4] == true)
			window.draw(Rules->getspr());
		if (draw[5] == true)
			window.draw(rul_s);
		if (draw[6] == true)
			window.draw(Ex_r->getspr());
		if (draw[7] == true)
			window.draw(Ex_g->getspr());
		if ((mode == 2) || (mode == 3))
		{
			if (mode == 2)
				window.draw(w1_s);
			else
				window.draw(w2_s);
			window.draw(Re_g->getspr());
		}
		window.display();

	}
	return 0;
}
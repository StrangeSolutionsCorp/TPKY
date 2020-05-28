#define _CRT_SECURE_NO_WARNING

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <dos.h>
#include "Button.h"
#include "Coll.h"
#include <SFML\Window/Mouse.hpp>
#include <SFML\Graphics/Text.hpp>

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
	float mass;
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

int drawMenu(RenderWindow& window, int actwind);

int main()
{
	RenderWindow window(VideoMode(WIGHT, HEIGHT), "TEST");
	int actwind = 0;

	stone Stone;
	ballista Balli1;
	ballista Balli2;

	Image ballista1;
	Image b1_anim[10];
	ballista1.loadFromFile("Bal/1_1.png");
	b1_anim[0].loadFromFile("Bal/1_1.png");
	b1_anim[1].loadFromFile("Bal/1_2.png");
	b1_anim[2].loadFromFile("Bal/1_3.png");
	b1_anim[3].loadFromFile("Bal/1_4.png");
	b1_anim[4].loadFromFile("Bal/1_5.png");
	b1_anim[5].loadFromFile("Bal/1_6.png");
	b1_anim[6].loadFromFile("Bal/1_7.png");
	b1_anim[7].loadFromFile("Bal/1_8.png");
	b1_anim[6].loadFromFile("Bal/1_9.png");
	b1_anim[7].loadFromFile("Bal/1_10.png");
	Texture bal_t;
	bal_t.loadFromImage(ballista1);
	Sprite bal1_s;
	bal1_s.setTexture(bal_t);
	bal1_s.setPosition(100, FLOOR-50);
	Balli1.x = 100;
	Balli1.y = FLOOR-50;
	Balli1.speed = 0;
	Balli1.angle = 0;
	Balli1.mass = 50;
	Balli1.petrol = PETROL;

	Image deg_1;
	Image d1_anim[6];
	deg_1.loadFromFile("Deg1/degree1.png");
	d1_anim[0].loadFromFile("Deg1/degree1.png");
	d1_anim[1].loadFromFile("Deg1/degree1_1.png");
	d1_anim[2].loadFromFile("Deg1/degree1_2.png");
	d1_anim[3].loadFromFile("Deg1/degree1_3.png");
	d1_anim[4].loadFromFile("Deg1/degree1_4.png");
	d1_anim[5].loadFromFile("Deg1/degree1_5.png");
	Texture d_t;
	d_t.loadFromImage(deg_1);
	Sprite d1_hud;
	d1_hud.setTexture(d_t);
	d1_hud.setPosition(80, 70);

	Image sc_1;
	Image sc1_anim[7];
	sc_1.loadFromFile("Scale1/sacle1.png");
	sc1_anim[0].loadFromFile("Scale1/sacle1.png");
	sc1_anim[1].loadFromFile("Scale1/sacle1_1.png");
	sc1_anim[2].loadFromFile("Scale1/sacle1_2.png");
	sc1_anim[3].loadFromFile("Scale1/sacle1_3.png");
	sc1_anim[4].loadFromFile("Scale1/sacle1_4.png");
	sc1_anim[5].loadFromFile("Scale1/sacle1_5.png");
	sc1_anim[6].loadFromFile("Scale1/sacle1_6.png");
	Texture sc_t;
	sc_t.loadFromImage(sc_1);
	Sprite sc1_hud;
	sc1_hud.setTexture(sc_t);
	sc1_hud.setPosition(80, 170);

	Image ballista2;
	Image b2_anim[10];
	ballista2.loadFromFile("Bal/2_1.png");
	b2_anim[0].loadFromFile("Bal/2_1.png");
	b2_anim[1].loadFromFile("Bal/2_2.png");
	b2_anim[2].loadFromFile("Bal/2_3.png");
	b2_anim[3].loadFromFile("Bal/2_4.png");
	b2_anim[4].loadFromFile("Bal/2_5.png");
	b2_anim[5].loadFromFile("Bal/2_6.png");
	b2_anim[6].loadFromFile("Bal/2_7.png");
	b2_anim[7].loadFromFile("Bal/2_8.png");
	b2_anim[6].loadFromFile("Bal/2_9.png");
	b2_anim[7].loadFromFile("Bal/2_10.png");
	Texture bal2_t;
	bal2_t.loadFromImage(ballista2);
	Sprite bal2_s;
	bal2_s.setTexture(bal2_t);
	bal2_s.setPosition(1100, FLOOR-50);
	Balli2.x = 1100;
	Balli2.y = FLOOR-50;
	Balli2.speed = 0;
	Balli2.angle = 0;
	Balli2.mass = 50;
	Balli2.petrol = PETROL;

	Image deg_2;
	Image d2_anim[6];
	deg_2.loadFromFile("Deg2/degree2.png");
	d2_anim[0].loadFromFile("Deg2/degree2.png");
	d2_anim[1].loadFromFile("Deg2/degree2_1.png");
	d2_anim[2].loadFromFile("Deg2/degree2_2.png");
	d2_anim[3].loadFromFile("Deg2/degree2_3.png");
	d2_anim[4].loadFromFile("Deg2/degree2_4.png");
	d2_anim[5].loadFromFile("Deg2/degree2_5.png");
	Texture d2_t;
	d2_t.loadFromImage(deg_2);
	Sprite d2_hud;
	d2_hud.setTexture(d2_t);
	d2_hud.setPosition(1100, 70);

	Image sc_2;
	Image sc2_anim[7];
	sc_2.loadFromFile("Scale2/scale2.png");
	sc2_anim[0].loadFromFile("Scale2/scale2.png");
	sc2_anim[1].loadFromFile("Scale2/scale2_1.png");
	sc2_anim[2].loadFromFile("Scale2/scale2_2.png");
	sc2_anim[3].loadFromFile("Scale2/scale2_3.png");
	sc2_anim[4].loadFromFile("Scale2/scale2_4.png");
	sc2_anim[5].loadFromFile("Scale2/scale2_5.png");
	sc2_anim[6].loadFromFile("Scale2/scale2_6.png");
	Texture sc2_t;
	sc2_t.loadFromImage(sc_2);
	Sprite sc2_hud;
	sc2_hud.setTexture(sc2_t);
	sc2_hud.setPosition(1150, 170);

	Image stone;
	stone.loadFromFile("stone1.png");
	Texture stone_t;
	stone_t.loadFromImage(stone);
	Sprite stone_s;
	stone_s.setTexture(stone_t);

	Image fl;
	fl.loadFromFile("floor.png");
	Texture fl_t;
	fl_t.loadFromImage(fl);
	Sprite fl_s;
	fl_s.setTexture(fl_t);
	fl_s.setPosition(0, FLOOR);
	fl_s.setScale(1.5, 1.5);

	Image sky;
	sky.loadFromFile("sky.png");
	Texture sky_t;
	sky_t.loadFromImage(sky);
	Sprite sky_s;
	sky_s.setTexture(sky_t);
	sky_s.setPosition(0, 0);

	Button* BattonExit1;
	BattonExit1 = new Button(500, 200, "bu2.png", "bu1.png", "Test");

	Vector2i mous;
	Text tecst;

	double time = 0;
	int shoot_fl = 0;
	bool role = 0;
	int coolider;
	int mode = 0;
	Time t2 = milliseconds(250);

	bool draw[4] = {false, true, true, true};


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (mode == 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (role == 0)
				{
					if (Balli1.petrol >= 0)
					{
						bal1_s.move(-0.5, 0);
						Balli1.x -= 0.5;
						Balli1.petrol -= 2.5;
					}
				}
				else if (role == 1)
				{
					if (Balli2.petrol >= 0)
					{
						bal2_s.move(-0.5, 0);
						Balli2.x -= 0.5;
						Balli2.petrol -= 2.5;
					}
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (role == 0)
				{
					if (Balli1.petrol >= 0)
					{
						bal1_s.move(0.5, 0);
						Balli1.x += 0.5;
						Balli1.petrol -= 2.5;
					}
				}
				else if (role == 1)
				{
					if (Balli2.petrol >= 0)
					{
						bal2_s.move(0.5, 0);
						Balli2.x += 0.5;
						Balli2.petrol -= 2.5;
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
						bal_t.update(b1_anim[0]);
					if (Balli1.speed >= 10)
						bal_t.update(b1_anim[1]);
					if (Balli1.speed >= 20)
						bal_t.update(b1_anim[2]);
					if (Balli1.speed >= 30)
						bal_t.update(b1_anim[3]);
					if (Balli1.speed >= 40)
						bal_t.update(b1_anim[4]);
					if (Balli1.speed >= 50)
						bal_t.update(b1_anim[5]);
					std::cout << "spd++ = " << Balli1.speed << std::endl;
				}
				else if (role == 1)
				{
					if (Balli2.speed <= 60)
						Balli2.speed += 0.1;
					if (Balli2.speed == 0)
						bal2_t.update(b2_anim[0]);
					if (Balli2.speed >= 10)
						bal2_t.update(b2_anim[1]);
					if (Balli2.speed >= 20)
						bal2_t.update(b2_anim[2]);
					if (Balli2.speed >= 30)
						bal2_t.update(b2_anim[3]);
					if (Balli2.speed >= 40)
						bal2_t.update(b2_anim[4]);
					if (Balli2.speed >= 50)
						bal2_t.update(b2_anim[5]);
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
					if ((Balli1.angle >= 0)&&(Balli1.angle < 0.21))
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
			else if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				if (role == 0)
				{
					if (Balli1.mass <= 100)
						Balli1.mass += 5;
					sleep(t2);
					std::cout << "mass++ = " << Balli1.mass << std::endl;
				}
				else if (role == 1)
				{
					if (Balli2.mass <= 100)
						Balli2.mass += 5;
					sleep(t2);
					std::cout << "mass++ = " << Balli2.mass << std::endl;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::E))
			{
				if (role == 0)
				{
					if (Balli1.mass >= 6)
						Balli1.mass -= 5;
					sleep(t2);
					std::cout << "mass-- = " << Balli1.mass << std::endl;
				}
				else if (role == 1)
				{
					if (Balli2.mass >= 6)
						Balli2.mass -= 5;
					sleep(t2);
					std::cout << "mass-- = " << Balli2.mass << std::endl;
				}
			}
			if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space))
			{
				if (shoot_fl == 1)
				{
					if (role == 0)
					{
						time = 0;
						Stone.speed = (Balli1.speed * (50 / Balli1.mass));
						Stone.angle = Balli1.angle;
						Stone.mass = Balli1.mass;
						Stone.xs = Balli1.x + 100;
						Stone.ys = Balli1.y - 15;
					}
					else if (role == 1)
					{
						time = 0;
						Stone.speed = (Balli2.speed * (50 / Balli2.mass));
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
					while (Stone.yc <= FLOOR + 15)
					{
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
						}
						else if (shoot_fl == 2)
						{
							draw[1] = draw[0] = false;
							mode = 3;
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
						window.display();
						time += 0.01;
						std::cout << shoot_fl << std::endl;
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
		mous = Mouse::getPosition(window);
		BattonExit1->mouseChange(window, mous.x, mous.y);
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
			window.draw(BattonExit1->getspr());
		window.draw(d1_hud);
		window.draw(d2_hud);
		window.draw(sc1_hud);
		window.draw(sc2_hud);
		window.display();
		if ((BattonExit1->isPress(window, event.mouseButton.x, event.mouseButton.y)))
		{
			mode = 1;
			draw[3] = false;
		}
	}
	return 0;
}
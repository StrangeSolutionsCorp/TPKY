#define _CRT_SECURE_NO_WARNING

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <dos.h>
using namespace sf;

#define PETROL 500

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
	bool draw;
	float xc;
	float yc;
	float vy;
	float vx;
	float mass;
	float speed;
	float angle;
};

int main()
{
	RenderWindow window(VideoMode(1000, 600), "TEST");

	stone Stone;
	ballista Balli1;
	ballista Balli2;

	Image ballista1;
	ballista1.loadFromFile("sprite.png");
	Texture bal_t;
	bal_t.loadFromImage(ballista1);
	Sprite bal1_s;
	bal1_s.setTexture(bal_t);
	bal1_s.setPosition(100, 500);	Balli1.x = 100;	Balli1.y = 500;	Balli1.speed = 25;
	Balli1.angle = 0, 78;
	Balli1.mass = 50;
	Balli1.petrol = PETROL;	
	Image ballista2;
	ballista2.loadFromFile("sprite1.png");
	Texture bal2_t;
	bal2_t.loadFromImage(ballista2);
	Sprite bal2_s;
	bal2_s.setTexture(bal2_t);
	bal2_s.setPosition(900, 500);	Balli2.x = 900;	Balli2.y = 500;
	Balli2.speed = 25;
	Balli2.angle = 0, 78;
	Balli2.mass = 50;
	Balli2.petrol = PETROL;

	Image stone;
	stone.loadFromFile("stone.png");
	Texture stone_t;
	stone_t.loadFromImage(stone);
	Sprite stone_s;
	stone_s.setTexture(stone_t);

	double time = 0;
	bool shoot_fl = 0;
	bool role = 0;
	Time t2 = milliseconds(250);

	Stone.draw = false;


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
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
				if (Balli1.speed <= 60)
					Balli1.speed += 0.1;
				std::cout << "spd++ = " << Balli1.speed << std::endl;
			}
			else if (role == 1)
			{
				if (Balli2.speed <= 60)
					Balli2.speed += 0.1;
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
				std::cout << "angle++ = " << Balli1.angle * 57.3 << std::endl;
			}
			else if (role == 1)
			{
				if (Balli2.angle <= 1.52)
					Balli2.angle += 0.005;
				std::cout << "angle++ = " << Balli2.angle * 57.3 << std::endl;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (role == 0)
			{
				if (Balli1.angle >= 0.006)
					Balli1.angle -= 0.005;
				std::cout << "angle-- = " << Balli1.angle * 57.3 << std::endl;
			}
			else if (role == 1)
			{
				if (Balli2.angle >= 0.006)
					Balli2.angle -= 0.005;
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
					std::cout << "Ball x,y: " << Balli1.x << "," << Balli1.y << std::endl;
					Stone.speed = (Balli1.speed * (50 / Balli1.mass));
					Stone.angle = Balli1.angle;
					Stone.mass = Balli1.mass;
					Stone.xs = Balli1.x + 100;
					Stone.ys = Balli1.y - 15;
				}
				else if (role == 1)
				{
					time = 0;
					std::cout << "Ball x,y: " << Balli2.x << "," << Balli2.y << std::endl;
					Stone.speed = (Balli2.speed * (50 / Balli2.mass));
					Stone.angle = Balli2.angle;
					Stone.mass = Balli2.mass;
					Stone.xs = Balli2.x;
					Stone.ys = Balli2.y - 15;
				}
				stone_s.setPosition(Stone.xs, Stone.ys);
				Stone.draw = true;
				std::cout << "space" << std::endl;
				Stone.vx = Stone.vy = 0;
				if (role == 0)
					Stone.vx = Stone.speed * cos(Stone.angle);
				else if (role == 1)
					Stone.vx = -(Stone.speed * cos(Stone.angle));
				Stone.vy = Stone.speed * sin(Stone.angle);
				std::cout << "Start speed x,y: " << Stone.vx << "," << Stone.vy << std::endl;
				Stone.xc = Stone.yc = 0;
				Stone.xc = Stone.xs + Stone.vx * 0.001;
				Stone.yc = Stone.ys - Stone.vy * 0.001;
				stone_s.setPosition(Stone.xc, Stone.yc);
				std::cout << "Start x,y: " << Stone.xc << "," << Stone.yc << std::endl;
				while (Stone.yc <= 500)
				{
					Stone.xc = Stone.xs + (Stone.vx * time);
					Stone.yc = Stone.ys - (Stone.vy * time) + ((9.8 * time * time) / 2);
					stone_s.setPosition(Stone.xc, Stone.yc);
					window.clear();
					window.draw(bal1_s);
					window.draw(bal2_s);
					if (Stone.draw == true)
						window.draw(stone_s);
					window.display();
					std::cout << "x,y: " << Stone.xc << "," << Stone.yc << std::endl;
					std::cout << "speed x,y: " << Stone.vx << "," << Stone.vy << std::endl;
					std::cout << "+" << std::endl;
					time += 0.01;
				}
				Stone.draw = false;
				std::cout << "============" << std::endl;
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

		window.clear();
		window.draw(bal1_s);
		window.draw(bal2_s);
		if (Stone.draw == true)
			window.draw(stone_s);
		window.display();
	}
	return 0;
}
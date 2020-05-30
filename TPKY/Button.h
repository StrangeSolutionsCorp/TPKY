#pragma once

#include <SFML/Graphics.hpp>
#include <SFML\Graphics/Text.hpp>
#include "Files.h"
using namespace sf;
class Button {
	int xP;
	int yP;
	int xL;
	int yL;
	Sprite curr;
	Sprite text;
	Image text1;
	Texture m_t1;
	Image text2;
	Text but_t;
	bool state;
	bool chf;
	Font font;
public:
	Button(int x, int y, const char* first, const char* second, const String& string, int w, int h)
	{
		xP = x;
		yP = y;
		xL = w;
		yL = h;
		font.loadFromFile(AF);
		text1.loadFromFile(first);
		m_t1.loadFromImage(text1);
		text2.loadFromFile(second);
		curr.setTexture(m_t1);
		curr.setPosition(x, y);
		but_t.setFont(font);
		but_t.setString(string);
		but_t.setCharacterSize(15);
		but_t.setFillColor(sf::Color::White);
		but_t.setPosition(x, y);

		
		state = true;
		chf = false;

	};
	bool isPress(RenderWindow& window, int x, int y);
	Sprite getspr();
	Text gettext();
	void mouseChange(RenderWindow& window, int x, int y);
};
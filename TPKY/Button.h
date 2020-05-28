#pragma once

#include <SFML/Graphics.hpp>
#include <SFML\Graphics/Text.hpp>
using namespace sf;
class Button {
	int xP;
	int yP;
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
	Button(int x, int y, const char* first, const char* second, const String& string)
	{
		xP = x;
		yP = y;
		font.loadFromFile("arial.ttf");
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
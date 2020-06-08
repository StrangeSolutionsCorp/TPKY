#include "Button.h"
#include <iostream>
bool Button::isPress(RenderWindow& window, int x, int y)
{
	if ((x >= xP) && (y >= yP) && (x <= xP+xL) && (y <= yP+yL))
		return true;
	return false;
}
Sprite Button::getspr()
{
	return curr;
}
Text Button::gettext()
{
	return but_t;
}
void Button::mouseChange(RenderWindow& window, int x, int y)
{
	if ((x >= xP) && (y >= yP) && (x <= xP + xL) && (y <= yP + yL))
	{
		if (state == true)
		{
			state = true;
			chf = false;
		}
		else
		{
			state = true;
			chf = true;
		}
	}
	else
	{
		if (state == false)
		{
			state = false;
			chf = false;
		}
		else
		{
			state = false;
			chf = true;
		}
	}
	if (chf == true)
		if (state == true)
		{
			m_t1.update(text1);
		}
		else
		{
			m_t1.update(text2);
		}

}
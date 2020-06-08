#include "St_ch.h"
#include <iostream>
int st_ch::isPress(RenderWindow& window, int x, int y, int i, int role)
{
	if ((x >= coord[i].x) && (y >= coord[i].y) && (x <= coord[i].x + SW) && (y <= coord[i].y + SH))
	{
		if (true_state[i] == 0)
		{
			if (role == 0)
				true_state[i] = 1;
			else if (role == 1)
				true_state[i] = 2;
		}
		else if (true_state[i] == 1)
		{
			if (role == 1)
				true_state[i] = 3;
		}
		else if (true_state[i] == 2)
		{
			if (role == 0)
				true_state[i] = 3;
		}
		for (int j = 0; j < 4; j++)
		{
			if (j != i)
			{
				if (role == 0)
				{
					if (true_state[j] == 1)
						true_state[j] = 0;
					else if (true_state[j] == 3)
						true_state[j] = 2;
				}
				else if (role == 1)
				{
					if (true_state[j] == 2)
						true_state[j] = 0;
					else if (true_state[j] == 3)
						true_state[j] = 1;
				}
			}
		}
		switch (i)
		{
		case 0:
			return 15;
		case 1:
			return 35;
		case 2:
			return 55;
		case 3:
			return 75;
		default:
			break;
		}
	}
	return 0;
}
Sprite st_ch::getspr(int i)
{
	return st_s[i];
}
void st_ch::mouseChange(RenderWindow& window, int x, int y, int i, int role)
{
	if ((x >= coord[i].x) && (y >= coord[i].y) && (x <= coord[i].x + SW) && (y <= coord[i].y + SH))
	{
		if (state[i] == 0)
		{
			if (role == 0)
			{
				state[i] = 1;
				chf[i] = true;;
			}
			else if (role == 1)
			{
				state[i] = 2;
				chf[i] = true;
			}
		}
		else if (state[i] == 1)
		{
			if (role == 0)
			{
				chf[i] = false;
			}
			else if (role == 1)
			{
				state[i] = 3;
				chf[i] = true;
			}
		}
		else if (state[i] == 2)
		{
			if (role == 0)
			{
				state[i] = 3;
				chf[i] = true;
			}
			else if (role == 1)
			{
				chf[i] = false;
			}
		}
		else if (state[i] == 3)
		{
			if (role == 0)
			{
				chf[i] = false;
			}
			else if (role == 1)
			{
				chf[i] = false;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (j != i)
			{
				if (role == 0)
				{
					if (state[j] == 1)
					{
						state[j] = 0;
						chf[j] = true;
					}
					else if (state[j] == 3)
					{
						state[j] = 2;
						chf[j] = true;
					}
				}
				else if (role == 1)
				{
					if (state[j] == 2)
					{
						state[j] = 0;
						chf[j] = true;
					}
					else if (state[j] == 3)
					{
						state[j] = 1;
						chf[j] = true;
					}
				}
			}
		}
	}
	else
	{
		if (true_state[i] != state[i])
		{
			state[i] = true_state[i];
			chf[i] = true;
		}
	}
	if (chf[i] == true)
	{
		if (state[i] == 0)
			st_t[i].update(st_m[i][0]);
		if (state[i] == 1)
			st_t[i].update(st_m[i][1]);
		if (state[i] == 2)
			st_t[i].update(st_m[i][2]);
		if (state[i] == 3)
			st_t[i].update(st_m[i][3]);
	}

}
void st_ch::draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
		window.draw(st_s[i]);
}
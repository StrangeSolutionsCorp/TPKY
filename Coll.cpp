#include "Coll.h"
#include <iostream>

int collision(Sprite* stone, Sprite* bal, int role)
{
	Vector2f coord1, coord2;
	coord1 = stone->getPosition();
	coord2 = bal->getPosition();
	std::cout << (coord1.x - (coord2.x - 10.0)) << "|" << (coord1.x - (coord2.x + 150.0)) << "|" << (coord1.y - (coord2.y + 10)) << "|" << (coord1.y >= (coord2.y - 50.0)) << "\n";
	switch (role)
	{
	case 0:
	{
		if ((coord1.x >= (coord2.x-10.0)) && (coord1.x <= (coord2.x + 150.0)) && (coord1.y >= (coord2.y-10)) && ((coord1.y <= (coord2.y + 75.0))))
			return 1;
		else
			return 3;
	}
		break;
	case 1:
	{
		if ((coord1.x >= (coord2.x-10.0)) && (coord1.x <= (coord2.x + 150.0)) && (coord1.y >= (coord2.y-10)) && ((coord1.y <= (coord2.y + 75.0))))
			return 2;
		else
			return 3;
	}
		break;
	default:
		return 3;
		break;
	}
	return 3;
}

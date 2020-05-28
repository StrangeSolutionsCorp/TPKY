#include "Coll.h"
#include <iostream>

int collision(Sprite* stone, Sprite* bal, int role)
{
	Vector2f coord1, coord2;
	coord1 = stone->getPosition();
	coord2 = bal->getPosition();
	std::cout << coord1.x << "/" << coord1.y << ":" << coord2.x << "/" << coord2.y << std::endl;
	switch (role)
	{
	case 0:
	{
		if ((coord1.x >= coord2.x) && (coord1.x <= coord2.x + 100) && (coord1.y >= coord2.y) && ((coord1.y >= coord2.y - 50)))
			return 1;
		else
			return 3;
	}
		break;
	case 1:
	{
		if ((coord1.x >= coord2.x) && (coord1.x <= coord2.x + 100) && (coord1.y >= coord2.y) && ((coord1.y <= coord2.y - 50)))
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

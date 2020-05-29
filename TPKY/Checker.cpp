#include "Checker.h"

using namespace std;
int checker()
{
	ifstream file; // создаем объект класса ifstream
	try
	{
		file.open("Bal/1_1.png"); 
		file.open("Bal/1_2.png");
		file.open("Bal/1_3.png");
		file.open("Bal/1_4.png");
		file.open("Bal/1_5.png");
		file.open("Bal/1_6.png");
		file.open("Bal/1_7.png");
		file.open("Bal/1_8.png");
		file.open("Bal/1_9.png");
		file.open("Bal/1_10.png");

		file.open("Deg1/degree1.png");
		file.open("Deg1/degree1_1.png");
		file.open("Deg1/degree1_2.png");
		file.open("Deg1/degree1_3.png");
		file.open("Deg1/degree1_4.png");
		file.open("Deg1/degree1_5.png");

		file.open("Scale1/sacle1.png");
		file.open("Scale1/sacle1_1.png");
		file.open("Scale1/sacle1_2.png");
		file.open("Scale1/sacle1_3.png");
		file.open("Scale1/sacle1_4.png");
		file.open("Scale1/sacle1_5.png");
		file.open("Scale1/sacle1_6.png");

		file.open("Bal/2_1.png");
		file.open("Bal/2_2.png");
		file.open("Bal/2_3.png");
		file.open("Bal/2_4.png");
		file.open("Bal/2_5.png");
		file.open("Bal/2_6.png");
		file.open("Bal/2_7.png");
		file.open("Bal/2_8.png");
		file.open("Bal/2_9.png");
		file.open("Bal/2_10.png");

		file.open("Deg2/degree2.png");
		file.open("Deg2/degree2_1.png");
		file.open("Deg2/degree2_2.png");
		file.open("Deg2/degree2_3.png");
		file.open("Deg2/degree2_4.png");
		file.open("Deg2/degree2_5.png");

		file.open("Scale2/scale2.png");
		file.open("Scale2/scale2_1.png");
		file.open("Scale2/scale2_2.png");
		file.open("Scale2/scale2_3.png");
		file.open("Scale2/scale2_4.png");
		file.open("Scale2/scale2_5.png");
		file.open("Scale2/scale2_6.png");

		file.open("stone1.png");
		file.open("floor.png");
		file.open("petrol1.png");
		file.open("petrol2.png");
		file.open("arial.ttf");
		file.open("rul.png");
		file.open("w1.png");
		file.open("w2.png");

		file.open("bu1.png");
		file.open("bu2.png");
		file.open("bu3.png");
		file.open("bu4.png");
		file.open("bu5.png");
		file.open("bu6.png");
		file.open("bu7.png");
		file.open("bu8.png");
	}
	catch(...)
	{
		cout << "Error in files. Loadement is broken. File's not found/n";
		return 1;
	}

	return 0;
}

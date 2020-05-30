#include "Checker.h"

using namespace std;
int checker()
{
	int res;
	ifstream file; // создаем объект класса ifstream
	try
	{
		file.open("Bal/1_1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_6.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_7.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_8.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_9.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/1_10.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("Deg1/degree1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg1/degree1_1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg1/degree1_2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg1/degree1_3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg1/degree1_4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg1/degree1_5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("Scale1/sacle1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale1/sacle1_1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale1/sacle1_2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale1/sacle1_3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale1/sacle1_4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale1/sacle1_5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale1/sacle1_6.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("Bal/2_1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_6.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_7.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_8.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_9.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Bal/2_10.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("Deg2/degree2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg2/degree2_1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg2/degree2_2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg2/degree2_3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg2/degree2_4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Deg2/degree2_5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("Scale2/scale2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale2/scale2_1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale2/scale2_2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale2/scale2_3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale2/scale2_4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale2/scale2_5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("Scale2/scale2_6.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("stone1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("floor.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("petrol1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("petrol2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("arial.ttf");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("rul.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("w1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("w2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();

		file.open("bu1.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu2.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu3.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu4.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu5.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu6.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu7.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
		file.open("bu8.png");
		if (file.fail()) {
			throw 1;
		}
		file.close();
	}
	catch(int)
	{
		cout << "Error in files. Loadement is broken. File's not found/n";
		return 1;
	}
	catch (...)
	{
		cout << "Error in this code. Smthing is broken/n";
		return 1;
	}

	return 0;
}

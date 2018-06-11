#include<iostream>
#include<stdio.h>
using namespace std;

enum {
	CARA,
	CARB
};
class car {
	public:
		virtual void getName() = 0;
};
class carA: public car{
public:
	void getName()
	{
		printf("this is car A\n");
	}
};

class carB: public car{
public:
	void getName()
	{
		printf("this is car B\n");
	}
};

class carFactory {

public:
	static car* createCar(int type)
	{
		if (type == CARA) {
			return new carA();
		}
		else if (type == CARB) {
			return new carB();
		}
		else {
			return NULL;
		}
	}

};

int main()
{
	car* A = carFactory::createCar(CARA);
	A->getName();
	car* B = carFactory::createCar(CARB);
	B->getName();
	return 0;
}

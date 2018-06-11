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
	virtual car* createCar() = 0;

};

class carFactoryA:public carFactory {
public:
	car* createCar()
	{
		return new carA();
	}
};


class carFactoryB:public carFactory {
public:
	car* createCar()
	{
		return new carB();
	}
};

int main()
{
	carFactoryA AFactory;
	car* A = AFactory.createCar();
	A->getName();
	carFactoryB BFactory;
	car* B = BFactory.createCar();
	B->getName();
	return 0;
}

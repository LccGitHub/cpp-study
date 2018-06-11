#include<iostream>
#include<stdio.h>
using namespace std;

enum {
	CARA,
	CARB
};
class carLow {
	public:
		virtual void getName() = 0;
};
class carALow: public carLow{
public:
	void getName()
	{
		printf("this is low car A\n");
	}
};

class carBLow: public carLow{
public:
	void getName()
	{
		printf("this is low car B\n");
	}
};


class carHigh {
	public:
		virtual void getName() = 0;
};
class carAHigh: public carHigh{
public:
	void getName()
	{
		printf("this is High High car A\n");
	}
};

class carBHigh: public carHigh{
public:
	void getName()
	{
		printf("this is High car B\n");
	}
};

class carFactory {

public:
	virtual carLow* createCarLow() = 0;
	virtual carHigh* createCarHigh() = 0;

};

class carFactoryA:public carFactory {
public:
	carLow* createCarLow()
	{
		return new carALow();
	}

	carHigh* createCarHigh()
	{
		return new carAHigh();
	}
};


class carFactoryB:public carFactory {
public:

	carLow* createCarLow()
	{
		return new carBLow();
	}

	carHigh* createCarHigh()
	{
		return new carBHigh();
	}

};

int main()
{
	carFactoryA AFactory;
	carLow* A = AFactory.createCarLow();
	A->getName();
	carFactoryB BFactory;
	carHigh* B = BFactory.createCarHigh();
	B->getName();
	return 0;
}

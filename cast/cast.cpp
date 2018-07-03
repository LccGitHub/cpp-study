#include<stdio.h>
#include<stdlib.h>

class Base {
public:
	virtual ~Base(){}
};

class Derive:public Base {
};

class Derive1:public Base {
};
class A{
};

int main()
{
	Base* base = new Base;
	Derive* derive = new Derive;
	Derive1* derive1 = new Derive1;
	A* a = new A;
	derive = static_cast<Derive*>(base);
	//derive = static_cast<Derive*>(a);  /*error:static_cast from 'A *' to 'Derive *', which are not related by inheritance, is not allowed'*/
	derive = (Derive*)a;/* not report compile error*/

	derive = dynamic_cast<Derive*>(derive1);
	derive = dynamic_cast<Derive*>(base);
	return 0;
}



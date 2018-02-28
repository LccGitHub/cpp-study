#include<iostream>
#include<string>
using namespace std;

class Base
{
	public:
		virtual void a(int t)
		{
			cout<<"Base a print:"<<t<<endl;
		}
		virtual void b(int t)
		{
			cout<<"Base b print:"<<t<<endl;
		}
		void c(int t)
		{
			cout<<"Base c print:"<<t<<endl;
		}
};

class Derive:public Base
{
	public:
		virtual void a(int t)
		{
			cout<<"Derive print:"<<t<<endl;
		}
};

int main()
{
	Derive d;

	Base *pb = &d;
	Derive *pd = &d;

	pb->a(1);
	pd->a(1);
	pb->b(2);
	pd->b(2);
	pb->c(3);
	pd->c(3);

	return 0;
}



#include<iostream>
using namespace std;

class A
{
	public:
		A(int a)
			:ma(a)
		{
			cout<<"create "<<ma<<endl;
		}
		~A()
		{
			cout<<"delete "<<ma<<endl;
		}
		A operator+(const A& a2)
		{
			return A(this->ma + a2.ma);
		}

	private:
		int ma;
};

int main()
{
	A a1(1);
	A a2(2);

	const A& a3= a1+ a2;

	return 0;
}


#include<iostream>
#include<functional>
using namespace std;

class Role
{
	public:
		int compute(int a, int b);
};

int Role::compute(int a, int b)
{
	return a+ b;
}

int main()
{
	Role role;
	auto fn = bind(&Role::compute, &role, placeholders::_1, placeholders::_2);

	cout<<fn(4,6)<<endl;

	return 0;
}


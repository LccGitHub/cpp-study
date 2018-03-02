#include<iostream>
using namespace std;

struct A
{
	int a;
};

struct B:A
{
	int b;
};

int main()
{
	cout<<"struct A size is "<<sizeof(struct A)<<endl;
	cout<<"struct B size is "<<sizeof(struct B)<<endl;

	return 0;
}



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void fun(int i )
{
	cout<<' '<<i;
}

void fun_par(int i, const char* str )
{
	cout<<str<<i<<endl;
}

int main()
{
	vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	for_each(myvector.begin(), myvector.end(), fun);
	cout<<endl;
	for_each(myvector.begin(), myvector.end(), bind2nd(ptr_fun(fun_par), "Element:"));

	cout<<endl;

	return 0;
}


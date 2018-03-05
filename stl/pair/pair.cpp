#include<iostream>
#include<tuple>
#include<utility>
#include<functional>

using namespace std;

int main()
{
	int i = 0;
	auto p1 = make_pair(ref(i), ref(i));
	++p1.first;
	++p1.second;

	cout<<"i = "<<i<<endl;

	pair<char, char> p = make_pair('x', 'y');

	char c;
	
	tie(ignore, c) = p;

	cout<<"c = "<<c<<endl;

	return 0;
}


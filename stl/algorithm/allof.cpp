#include<iostream>
#include<algorithm>
#include<array>
using namespace std;


int main()
{
	array<int, 8> foo = {3,5,7,9,11,13,17,19};
	if (all_of(foo.begin(), foo.end(), [](int i ) {return i %2;}))
	{
		cout<<"all the elements are odd number"<<endl;
	}

	return 0;
}


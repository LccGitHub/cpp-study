#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	int foo[] = {1,2,3,4,5,6,7};
	vector<int > myvector(7);
	copy(foo, foo + 7, myvector.begin());

	for (vector<int>::iterator it = myvector.begin(); it<myvector.end(); ++it)
	{
		cout<<' '<<*it;
	}
	cout<<"\n";

	return 0;
}


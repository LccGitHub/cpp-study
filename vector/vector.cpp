
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4};
	int *b = a;
	int len = sizeof(a);

	vector<int> v= vector<int>(a, a+ len/sizeof(int));
	cout<<"v length is "<< v.size()<<endl;

	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";

	int *d = (int*)malloc(len);
	memcpy(d, &v[0], len);
	int i = 0;
	for (i = 0; i < len/sizeof(int); i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<"\n";

	v.clear();
	v.erase(remove(v.begin(), v.end(), 2), v.end());

	for (it = v.begin(); it != v.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
	return 0;
}


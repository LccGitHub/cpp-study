
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	string s("11");

	int t = strtol(s.c_str(), NULL, 16);
	cout<<t<<endl;
	return 0;
}




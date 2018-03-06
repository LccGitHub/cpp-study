#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;

	char tmp[] = "111";
	s.assign("hello");
	const char* t = s.c_str();

	s[4] = 'p';
	cout<<s<<" "<<s.size()<<" "<<t<<endl;

	return 0;
}


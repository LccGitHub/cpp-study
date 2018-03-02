
#include<iostream>
#include<string>
#include<memory>
#include<cstring>
using namespace std;


int main()
{
	string s(0, 0);
	cout<<"s size is "<<s.size()<<endl;

	string t(20, 0);
	memcpy((char*)(t.data()), "hello", 6);

	cout<<"t size is "<<t.size()<<endl;

	t.resize(6);
	cout<<"t size is "<<t.size()<<endl;

	string data1(6,0);
	data1[0] = 0;
	data1[1] = 0;
	data1[2] = 0;
	data1[3] = 0;
	data1[4] = 1;
	data1[5] = 10;
	cout<<"data1 size is "<<data1.size()<<" length is "<<data1.length()<<endl;

	int i = 0;
	for (i = 0; i < data1.size(); i++)
	{
		cout<<data1.c_str()[i]<<endl;
	}

	return 0;
}

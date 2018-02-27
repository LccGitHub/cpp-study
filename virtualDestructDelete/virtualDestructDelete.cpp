/*************************************************************************
	> File Name: virtualDestructDelete.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 27 Feb 2018 04:55:41 PM CST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;


class base 
{
    public:
		base()
		{
			cout<<"this is base construct funciton \n" <<endl;
		}
		virtual ~base()
		{
			cout<<"this is base deconstruct funciton \n" <<endl;
		}
};

class derive :public base
{
	public:
		derive()
			:test(new int)
		{
			cout<<"this is derive construct funciton \n" <<endl;
		}
		~derive()
		{
			delete test;
			cout<<"this is derive deconstruct funciton \n" <<endl;
		}
	private:
		int *test;
};

int main()
{
	base *b = new derive;

	delete b;

	derive b1;
	return 0;
}

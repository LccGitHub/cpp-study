#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class test {
public:
	test(int size)
		: mSize(size)
	{
		mData = new int[size];
	}
	~test()
	{
		delete mData;
	}
	test(const test& other)
		: mSize(other.mSize)
	{
		mData = new int[mSize];
		memcpy(mData, other.mData, mSize);
	}
private:
	int mSize;
	int* mData;

};

int main()
{
	test a(2);
	test b = a;
	return 0;
}


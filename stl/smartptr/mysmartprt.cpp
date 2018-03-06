/*************************************************************************
  > File Name: ptr.cpp
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: Mon 05 Mar 2018 06:16:25 PM CST
 ************************************************************************/

#include<iostream>

using namespace std;

template<typename T>
class myShared_ptr
{
	public:
		myShared_ptr(T* p): mPtr(p), mRefCounter(new int(1))
	{
		cout<<"parameter construct funciton"<<endl;
	}
		myShared_ptr(const myShared_ptr<T>& other): mPtr(other.mPtr), mRefCounter(other.mRefCounter)
	{
		++(*mRefCounter);
		cout<<"copy construct "<<endl;
	}
		~myShared_ptr()
		{
			cout<<"Deconstruct mRefCunter = "<<*mRefCounter<<endl;
			if (--*mRefCounter == 0)
			{
				cout<<"Deconstruct have finish! mRefCunter = "<<*mRefCounter<<endl;
				delete mPtr;
				delete mRefCounter;
				mPtr = NULL;
				mRefCounter = NULL;
			}
		}

		myShared_ptr operator=(T* p)
		{
			++*p.mRefCounter;
			if (this->mPtr && 0 == --*this->mRefCounter)
			{
				delete mPtr;
				delete mRefCounter;
			}
			this->mPtr = p.mPtr;
			this->mRefCounter = p.Refcounter;
			return *this;
		}
		T* operator->()
		{
			cout<<"this is -> operator"<<endl;
			return mPtr;
		}
		T& operator*()
		{
			cout<<"this is . operator"<<endl;
			return *mPtr;
		}
		int getRef() {return *mRefCounter;}

	private:
		T* mPtr;
		int* mRefCounter;

};


int main()
{
	myShared_ptr<int> p1 = new int(1);
	cout<<"counter = "<<p1.getRef()<<endl;
	myShared_ptr<int> p2 = new int(2);
	cout<<"counter = "<<p2.getRef()<<endl;
	myShared_ptr<int> p3 = p1;
	cout<<"counter = "<<p1.getRef()<<endl;

	return 0;

}

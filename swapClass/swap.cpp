/*************************************************************************
  > File Name: swap.cpp
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: Fri 02 Mar 2018 03:17:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Base
{
	public:
		Base(int a)
			:a(a)
		{
		}
		Base(const Base& t)
		{
			cout<<"create Base by construct "<<endl;
		}
		Base& operator=(const Base& t)
		{
			cout<<"create Base by copy "<<endl;
		}
		void show()
		{
			cout<<"a is "<<a<<endl;
		}

		void swap(Base& other)
		{
			using std::swap;
			swap(a, other.a);
		}

	private:
		int a;
};

// std::swap 特化版本， 如果需要置换Base， 调用其swap成员函数.
namespace std
{
	template<>
		void swap(Base& a, Base& b)
		{
			a.swap(b);
		}
}


int main()
{
	Base ca(2);
	Base cb(3);

	swap<Base>(ca,cb);

	ca.show();
	cb.show();
}

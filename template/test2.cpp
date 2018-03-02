
#include<iostream>
#include<string.h>

using namespace std;

template<typename T>
class Base
{
	protected:
		void invert(size_t n)
		{
			cout<<"this is base invert, n:"<<n<<endl;
		}
};

template<typename T, size_t n>
class Derived: private Base<T>
{
	private:
		using Base<T>::invert;

	public:
		void invert()
		{
			invert(n);
			cout<<"this is derived invert, n:"<<n<<endl;
		}
};


int main()
{
	Derived<int,5> d;
	d.invert();


	return 0;
}


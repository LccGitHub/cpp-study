
#include<iostream>
using namespace std;

class Bitmap
{
	public:
		Bitmap()
			:b(10)
		{

		}
		~Bitmap()
		{
			delete []p;
		}

		Bitmap(Bitmap& a)
		{

				p = new int[1000000000000];
				cout<<" 111 new success"<<endl;
		}

		int b;
	private:
		int *p;
};

class Widget
{
	public:
		Widget(int x)
			:pb(new Bitmap)
		{
			cout<<"Widget:"<<x<<endl;
		}
		Widget& operator=(const Widget& rhs)
		{
			cout<<"operator = start"<<endl;
			Bitmap* pOrig = pb; 
			pb = new Bitmap(*rhs.pb);
			cout<<"only new success, i can be called"<<endl;
			delete pOrig;
			cout<<"operator = finish"<<endl;
			return *this;
		}

	
		Bitmap* pb;
};

int main()
{
	Widget a(1);
	cout<<"a.pb->b="<<a.pb->b<<endl;
	Widget b(2);
	cout<<"b.pb->b="<<b.pb->b<<endl;
	try {
		b = a;
	}
	catch (exception& e){
		cout << "i am here!!! " << e.what() << "\n" ;
	}
	cout<<"b.pb->b="<<b.pb->b<<endl;


	cout<<"main finish"<<endl;
	return 1;
}


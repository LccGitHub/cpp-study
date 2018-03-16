#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

pthread_mutex_t mutex;
void* thread_func(void* arg);


class Singleton
{
	/*when contruct funciton is private, will not derived, only protected construct, can be derive*/
	/*private*/protected:
		Singleton()
		{
			cout<<"Singlton construct"<<endl;
		}

	public:
		static Singleton* instance();

	private:
		static Singleton* p ;
};
Singleton* Singleton::p = new Singleton;

Singleton* Singleton::instance()
{
	return p;
}

class derived: public Singleton
{
	public:
		derived(){
			cout<<"derived construct"<<endl;
		}
		~derived(){}
};



int main()
{
	derived d;
	Singleton* p = Singleton::instance();
	cout<<d.instance()<<endl;
	cout<<p<<endl;
	


	return 0;
}


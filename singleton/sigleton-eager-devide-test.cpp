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
		/*when call Singleton::instance(), deconstruct will not be called when end*/
		~Singleton()
		{
			cout<<"Singlton deconstruct"<<endl;
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
#if 1
class derived: public Singleton
{
	public:
		derived(){
			cout<<"derived construct"<<endl;
		}
		~derived(){
			cout<<"derived deconstruct"<<endl;
		}
};

#endif

int main()
{
	derived d;
	Singleton* p = Singleton::instance();
	cout<<d.instance()<<endl;
	cout<<p<<endl;
	


	return 0;
}


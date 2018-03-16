#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

pthread_mutex_t mutex;
void* thread_func(void* arg);


class Singleton
{
	private:
		Singleton()
		{

		}

	public:
		static Singleton* instance(int a);

		int getvaule()
		{
			return test;
		}

		static void setvaule(int a)
		{
			test = a;
		}
	private:
		static int test;
		static Singleton* p ;
};
Singleton* Singleton::p = new Singleton;
int Singleton::test = 0;

Singleton* Singleton::instance(int a)
{
	setvaule(a);/*this is for test*/
	return p;
}


void* thread_func(void* arg)
{
	int res = -1, res1 = -1;
	Singleton* p = NULL;
	p = Singleton::instance(1);
	res = p->getvaule();
	cout<<"result ="<<res<<endl;
	cout<<"p ="<<p<<endl;
	return NULL;
}

void* thread1_func(void* arg)
{
	int res = -1, res1 = -1;
	Singleton* p = NULL;
	p = Singleton::instance(2);
	res = p->getvaule();
	cout<<"result1 ="<<res<<endl;
	cout<<"p ="<<p<<endl;
	return NULL;
}

int main()
{
	pthread_t thr1, thr2;
	pthread_create(&thr1, NULL, thread_func, NULL);
	pthread_create(&thr2, NULL, thread1_func, NULL);
	//	pthread_mutex_init(&mutex, NULL);

	while(1)
	{
	}
	return 0;
}

